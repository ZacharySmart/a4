THIS README FILE IS PRACTICALLY AN EXACT COPY OF THE ASSIGNMENT 2 SOLUTION FILE
- it is this programmer’s belief that efficiency is key. As such the included script which automatically populates the Beatles database provides ample proof of the functioning of these refactored classes.

unzip in linux with ‘unzip assignment3.zip’

To compile:

make clean mytunes

To run:

./mytunes

The program reads the insert_beatles_tracks_rev1.txt script on startup.
To disable this behaviour comment out the lines:

  //initialize app with input script
  Command cmd = Command(".read insert_beatles_tracks_rev1.txt");
  executeCommand(cmd);

in the run() method at the start of the UI.cpp file.

(c) Zachary Smart 2017 