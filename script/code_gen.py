import argparse
import re
import os
import yaml


def interpolate(placeholder: str, rules: dict):
    interpolated = placeholder
    for key, val in rules.items():
        interpolated = interpolated.replace(key, val)
    return interpolated


def concatenate(base: str, sub: str, is_suffix = True):
    return base + sub if is_suffix else sub + base


def snake_case(camel_case: str):
    return re.sub(r'(?<!^)(?=[A-Z])', '_', camel_case).lower()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('class_yaml', help='the class.yaml file path')
    parser.add_argument('src_template_directory', help='the src directory where code templates are stored')
    parser.add_argument('destination_directory', help='the destination directory to store generated codes')
    parser.add_argument('--prefix', help='add substring to class prefix',action='store_true')
    args = parser.parse_args()
    yaml_path = os.path.abspath(args.class_yaml)
    yaml_file_name = os.path.basename(yaml_path)
    path_tokens = os.path.splitext(yaml_file_name)
    yaml_extension = path_tokens[-1]
    file_name = path_tokens[-2]
    class_name = file_name.capitalize()
    src_path = os.path.abspath(args.src_template_directory)
    dest_path = os.path.abspath(args.destination_directory)
    is_suffix = not args.prefix

    with open(yaml_path) as f:
        yamlObject = yaml.load(f, Loader=yaml.CBaseLoader)

    dest_path = os.path.join(dest_path, snake_case(class_name))
    if not os.path.exists(dest_path):
        os.mkdir(dest_path)

    def walk(root: str, parent: str, tree: dict, fold_dirs=1):
        base_class = concatenate(class_name, parent, is_suffix)
        
        for child in tree[parent]:
            derieved_class = concatenate(class_name, child, is_suffix)
            base_class_inheritance = f': public {base_class}' if parent != 'root' else ''
            base_class_header = f'#include "{base_class}.h"' if parent != 'root' else ''

            rules = {'{%BASECLASS_INHERITANCE%}': base_class_inheritance,
                     '{%BASECLASS_HEADER%}': base_class_header,
                     '{%DERIVEDCLASS%}': derieved_class,
                     '{%DERIVEDCLASS_HEADER%}': derieved_class.upper()}

            # read all files from the selected template folder
            # interpolate each file and save to current path
            for cur_dir, _, files in os.walk(src_path):
                for file in files:
                    with open(os.path.join(cur_dir, file)) as code_file:
                        code = code_file.read()
                    file_extension = os.path.splitext(file)[-1]
                    new_file_path = os.path.join(root, derieved_class + file_extension)
                    interpolated_code = interpolate(code, rules)
                    
                    if not os.path.exists(new_file_path):
                        with open(new_file_path, 'w') as new_code_file:
                            new_code_file.write(interpolated_code)

            if tree[parent][child]:
                folder_path = root
                if fold_dirs <= 0:
                    folder_path = os.path.join(root, snake_case(derieved_class))
                    os.mkdir(folder_path)
                walk(folder_path, child, tree[parent], fold_dirs=fold_dirs-1)
    
    rootObject = {'root': yamlObject}
    walk(dest_path, 'root', rootObject)