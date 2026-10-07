def count_votes(votes):
    """Returns a dictionary that maps each candidate to their number of votes."""
    count = {}
    for x in votes:
        if x in count:
            count[x]+= 1
        else:
            count[x]= 1
    return count
def announce_result(votes):
    """Print each candidate's votes, the winner (or tie), and candidates with fewer than 2 votes."""
    counts = count_votes(votes)
    print("Candidates with their votes:")
    print(counts)
    highest_score = max(counts.values())
    winner = [k for k, v in counts.items() if v == highest_score]
    if len(winner) == 1:
        print("Winner:", winner[0])
    else:
        print("Tie between:", ", ".join(winner))
        
    print("Candidate who received fewer then two votes:")
    less_than_two = lambda count: [name for name, v in counts.items() if v < 2]
    print(less_than_two(count)) 


votes1 = ["Ali", "Sara", "Ali", "Hamza", "Sara", "Ali", "Zara",
"Hamza", "Sara", "Sara"]
votes2 = ["Ali", "Sara", "Sara", "Ali", "Zara"]
announce_result(votes1)
announce_result(votes2)
