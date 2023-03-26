#   monty

## The Monty Language
is a scripting language that is first compiled into Monty byte codes.
It relies on a unique stack, with specific instructions to manipulate it.
The project is an interpreter for Monty ByteCodes files.

### Monty byte code files
1. Files containing Monty byte codes usually have `.m` extension.
 * Most of the industry uses this standard but it is not required by the specification of the language.
2. There is not more than one instruction per line.
 * There can be any number of spaces before or after the opcode and its argument.
 * They can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.

### The monty program
* Usage: `monty file`
 - where `file` is the path of the file containing Monty ByteCode
