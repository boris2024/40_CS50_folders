# 20230712 20230713

# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
#N = 1000
N = 1

def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []

    # TODO: Read teams into memory from file

    filename=sys.argv[1]

    with open(filename) as file:
        file_reader=csv.DictReader(file)

    # algo is just a variable name
    for i in file_reader:
        teams.append(i)

    for i in range(len(teams)):
        teams[i]['rating']=int((teams[i]['rating']))

    #print(teams)



    counts = {}

    # TODO: Simulate N tournaments and keep track of win counts

    for i in range(N):
        winner=simulate_tournament(teams)

        print(winner)


    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

    #file.close()

def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO

    winners_0=simulate_round(teams)

    winners_1=simulate_round(winners_0)

    winners_2=simulate_round(winners_1)

    winners_3=simulate_round(winners_2)

    champion=winners_3

    print(champion)

    return champion[0]["team"]


if __name__ == "__main__":
    main()