Compile with
g++ -Os -std=c++11 -lwiringPi adv_io.cpp binclock.cpp -o binclock

Run with
sudo ./binclock

super-user is necessary, because of WiringPi GPIO mode.
Feel free to share.
