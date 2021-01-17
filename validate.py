import os
import re
import filecmp


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def positive_print(msg):
    print(f'{bcolors.OKGREEN}{msg}{bcolors.ENDC}')


def negative_print(msg):
    print(f'{bcolors.FAIL}{msg}{bcolors.ENDC}')


if __name__ == "__main__":
    root_path = os.path.dirname(__file__)
    test_project_path = os.path.join(root_path, "tests", "project")
    for cur_dir, dirs, files in os.walk(test_project_path):
        cmp_files = [f for f in files if re.match(r'.+\.asm', f)]
        if not cmp_files:
            continue
        if len(cmp_files) != 2:
            print(f"{cmp_files} don't contain two files")
            continue
        if filecmp.cmp(os.path.join(cur_dir, cmp_files[0]), os.path.join(cur_dir, cmp_files[1]), shallow=False):
            positive_print(f'[O] {cmp_files[0]} and {cmp_files[1]} match!')
        else:
            negative_print(f'[X] {cmp_files[0]} AND {cmp_files[1]} DO NOT MATCH!')
        