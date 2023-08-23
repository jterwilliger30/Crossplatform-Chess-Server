# TODO
- To simplify development, I've made the decision to split off Qt-Chess into a server and two clients who communicate through said server. This repo will constitute the server, and a separate repo (doesn't exist yet) will be the cross-platform, lightweight client. 

- Decision... should clients be actual applications written in Qt, or a web browser that communicates with the server over HTTP
- Need to distinguish b/w singleplayer meaning vs. AI or singleplayer meaning one player plays both sides
- What to do about virtual destructor... probably not needed anymore with shared_ptrs

# Build
- Build assumes you have Protobuf 21.12 installed somewhere CMake can find it... while protobuf is in the externals folder, it is not currently dynamically compiled or linked. Building protobuf should just be as simple as calling 'cmake .' or 'cmake3', then 'make', then 'sudo make install'.
