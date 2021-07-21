# GenLib (WIP)

A set of C++ utilities to assist with generation of test data in combination with the popular `testlib.h`.

Data generation is being built with various types of sequences in mind and a rich
graph generator.

Additionally, there are also output tools that shorten common print 
statements of arrays, graphs, grids, etc.

Lastly, there are also some validation tools planned, especially with graphs (testing that graphs are connected, a tree, etc.).

**Fix this! (I'm sure I can improve on this overview, but I'll just leave this for my sake so I don't forget)**

## Setup

Make sure `python3` and `pip3` are installed.

Run the script `build.sh`, which will automatically build the headers into a single file (`genlib.h`).

Note that `testlib.h` is already included in the `genlib.h` as part of the build process, so including both headers is not necessary.

*Note: `build.sh` will NOT work on Windows (or anything that doesn't work 
with `online-judge-verify-helper`)*

# WIP

Honestly just everything...

* generators/range.hpp
* generators/sequence.hpp
* generators/tree.hpp
* generators/graph.hpp
* generators/output.hpp
