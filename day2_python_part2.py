def match_cubes(input_path:str):
    with open(input_path, "r") as f:
        lines = f.readlines()

    amount = 0
    for line in lines:
        color_map = {
        "red" : -1,
        "green" : -1,
        "blue" : -1
    }
        game_id, cube_sets = line.split(":")
        game_id = int(game_id.split()[1])
        cube_sets = cube_sets.strip().split(";")
        cond_satis = True
        for cubset in cube_sets:
            total_cubes = cubset.split(",")
            for cube in total_cubes:
                cube = cube.strip()
                quant, color = cube.split()
                color_map[color] = max(color_map[color], int(quant))
        
        power_of_set = 1
        for vals in color_map.values():
            power_of_set *= vals
        amount += power_of_set

    print(amount)

def main():
    path = "inpday2.txt"
    match_cubes(path)

main()