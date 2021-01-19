# VM Translator

This is a personal learning project that implements the virtual machine code translator introduced in the Coursea lecture: ["Build a Modern Computer from First Principles" by Professor Shimon Schocken](https://www.coursera.org/learn/nand2tetris2/home/welcome).

## What is virtual machine/language?

The "Virtual Machine" is an abstract computer that executes a middle language, better known as an intermediate language, that sits in between the translation of a high-level language to an assembly language. A common example is the Java's Bytecode, which is what made Java one of the most influential programming platform with the slogan: "Write once, run everywhere".

## What does the VM translator program do?

The VM translator translates/decodes a source intermediate language to a target assembly language. The source and target language specification is given for this lecture. The languages are called the "VM language" and the "Hack assembly language", respectively. Although these languages aren't sophisticated to serve complicated programming tasks, they sufficiently define the most foundational operations of any computer programs, such as arithmetic, logical, branching, and function call/return commands. The complete specification is explained throughout the lecture in "Building the VM Translator".

The correctness of the implementation can be checking by running the given test cases. The tools needed to run the translated assembly language can be downloaded from the [lecture's homepage](https://www.nand2tetris.org/software).

## How did I design and implement the program?

Although the lecture proposes a simple design, I personally wanted to design and implement a program that is more scalable, maintainable, and reusable in the hopes to improve my system design skills. I specifically focused on regarding to the following aspects:

- scaling with minimal modification when introduced with new specification and requirements
- designing clear state transferring components so that correctness can be discussed in a controlled manner.
- designing reusable software schemes and components for other similar translation programs, such as compilers and renderers

## How to run the program?

For those who are taking the course and wanting to see an example of how a completed translator would work:

- cmake (required)
    
    The project uses `cmake` as its meta-build system. Run `cmake -S . -B out` in the project's root folder to generate build scripts for an installed compiler.

- Windows OS and Visual Studio IDE (required if you want to run the `.bat` scripts)

    If you're running on Windows and have Visual Studio IDE installed in you're environment PATH, you can run the `build.bat` script to generate build scripts for the msbuild compiler which is part of the Visual Studio IDE.

    Then, you can run the `run.bat` script to generate hack assembly(`.asm`) files in the `tests` folder which are translated from the virtual language(`.vm`) source files.






