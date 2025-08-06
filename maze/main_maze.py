# -*- coding: utf-8 -*-
from maze import Maze
from collections import deque

def depth_first_search(maze: Maze):
    start_pos = maze.get_init_pos_player()
    stack = deque([start_pos])
    visited = set()

    while stack:
        current_pos = stack.pop()

        if current_pos in visited:
            continue

        visited.add(current_pos)
        maze.mov_player(current_pos)

        if maze.find_prize(current_pos):
            print("Prêmio encontrado em:", current_pos)
            return True

        x, y = current_pos
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        for dx, dy in directions:
            neighbor = (x + dx, y + dy)
            if neighbor not in visited and maze.is_free(neighbor):
                stack.append(neighbor)

    print("Prêmio não encontrado")
    return False

if __name__ == "__main__":
    maze_path = "maze.txt"
    maze = Maze()
    maze.load_from_csv(maze_path)
    maze.init_player()
    depth_first_search(maze)
    maze.run()
