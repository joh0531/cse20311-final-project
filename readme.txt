
General Idea for Project
SNEK
SNEK X 2
Basic snake
only power up is the food

Planning
1. Spawn as a dot in the middle of the screen
2. spawn a food somewhere, initialize speed
3. Let user control dot, based off of user input - initialize direction
4. user runs around, dies if goes into a wall or hits self
5. For checking algorithm, must increment whole snake first, then check for death
6. For eat-food algorithm, depending on number of new pixels gained, that amount is spawned one at a time whenever the snake's but moves off of pixel.
7. Whenever food is eated, increase speed
8. When snake dead, end the game, and then go back to main
9. main has option to try again. If not, quit.



Classes
board-object - bigger class that food and pixel will inherit from
food - position
pixel-snake - eat-food algorithm - speed algorithm - moving algorithm which includes a check-death algorithm - keep score
pixel - position, draw-method, move-method,
game - Initializing the game, and then it runs the game, draw-score
