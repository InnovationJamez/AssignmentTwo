# generate a maze using the growing tree method
./exe -gg seed --sb filename.maze # generate with seed value, save binary file
./exe -gg seed --sv filename.svg # generate with seed value, save svg file
./exe -gg seed --sb filename.maze --sv filename.svg # gen with seed, save binary, save svg

# generate a maze using Prim’s algorithm
./exe -gp seed --sb filename.maze # generate with seed value, save binary file
./exe -gp seed --sv filename.svg # generate with seed value, save svg file
./exe -gp seed --sb filename.maze --sv filename.svg # gen with seed, save binary, save svg

# generate a maze using the recursive backing algorithm
./exe -gr seed --sb filename.maze # generate with seed value, save binary file
./exe -gr seed --sv filename.svg # generate with seed value, save svg file
./exe -gr seed --sb filename.maze --sv filename.svg # gen with seed, save binary, save svg

# load binary file and save svg file
./exe --lb filename.maze --sv filename.svg 

# solve the maze using the Maze-routing algorithm
./exe --pm --sb filename.maze --sv filename.svg #solve maze and add solution svg file


changes that I have made

I did not initaally make carvePath a virtual function, but I had to as I changed the functions 
that it called in prim and recursive. 