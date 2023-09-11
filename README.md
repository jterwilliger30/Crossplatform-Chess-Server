# What's New
- This software now compiles on Windows... just need to install CMAKE and MSVC v143 SDK & Co.

# TODO
- I really didn't think this through... randomly assigning colors means black sometimes goes first.
- Need to distinguish b/w singleplayer meaning vs. AI or singleplayer meaning one player plays both sides
- What to do about virtual destructor... probably not needed anymore with shared_ptrs


# Building Chess-Server (requires Protobuf)
- FOR WINDOWS: 'cmake .', then 'cmake --build . --config Release'
- FOR _nix: 'cmake .', then make

# Building Protobuf
- Build assumes you have Protobuf 21.12 installed somewhere CMake can find it... while protobuf is in the externals folder, it is not currently dynamically compiled or linked. 

- FOR WINDOWS: 'cmake .', then 'cmake --build . --config Release --target install'
- FOR *nix: Building protobuf should just be as simple as calling 'cmake .' or 'cmake3', then 'make', then 'sudo make install'.
