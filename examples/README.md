# Examples

Every C file in this directory (not a subdirectory!) is a self-contained example, with the exception of `common.h` and `common.c` that are used other examples. Some examples might use some or all the assets from the assets directory. All third-party libraries used by the examples are vendored in the external folder.

# Building an example

Every example is written so that compiling it should be as simple as running a single command, for instance:

```sh
gcc ./basic_text.c -o ./basic_text
```

or
```cmd
cl.exe ./basic_text.c
```
etc.
