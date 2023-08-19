# TODO
- To simplify development, I've made the decision to split off Qt-Chess into a server and two clients who communicate through said server. This repo will constitute the server, and a separate repo (doesn't exist yet) will be the cross-platform, lightweight client. 

- Decision... should clients be actual applications written in Qt, or a web browser that communicates with the server over HTTP
- Remove Qt from this repo... server has no need of GUI.
- What to do about virtual destructor... probably not needed anymore with shared_ptrs
- Unicode characters printed by print_board() don't work for Windows... need to check linux as well
- It seems the colors of the unicode chess pieces are not standardized :(

# Build
- Build assumes you have Protobuf 21.12 installed to /usr/local/lib and /usr/local/include... while protobuf is in the externals folder, it is not currently dynamically compiled or linked
