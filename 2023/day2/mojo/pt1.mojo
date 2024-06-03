fn main() raises:

    var data: String
    with open("data", "r") as f:
        data = f.read()

    let lines: DynamicVector[String] = data.split("\n")
    print(lines[1])
    for i in range(len(lines) - 1):
        var line = lines[i]

        var game_info: String = line.split(":")[1]
        var games: DynamicVector[String] = game_info.split(";")
        for j in range(len(games) - 1):
            var game: String = games[j]

            var sides: DynamicVector[String] = game.split(",")
            for k in range(len(sides)-1):
                var side: String = sides[k]

                print(side)
                var side_info: DynamicVector[String] = side.split(" ")
                for l in range(len(side_info)):
                    if side_info[l] == " ":
                        




