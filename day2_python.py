color_map = {
    "red" : 12,
    "green" : 13,
    "blue" : 14
}

def match_cubes(input_path:str):
    with open(input_path, "r") as f:
        lines = f.readlines()

    amount = 0
    for line in lines:
        game_id, cube_sets = line.split(":")
        game_id = int(game_id.split()[1])
        cube_sets = cube_sets.strip().split(";")
        cond_satis = True
        for cubset in cube_sets:
            total_cubes = cubset.split(",")
            for cube in total_cubes:
                cube = cube.strip()
                quant, color = cube.split()
                if (color_map[color] < int(quant)): 
                    cond_satis = False
                    break
        
        if (cond_satis) : amount += game_id

    print(amount)

def main():
    path = "inpday2.txt"
    match_cubes(path)

main()