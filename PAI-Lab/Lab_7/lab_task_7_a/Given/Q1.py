# Lab Task 7 - Question 1 (starter code)
# The functions curve() and viva_schedule() are already written for you.
# Complete generate_marks() and every TODO below. Do not change the given functions.
import math
import random
import statistics
from datetime import date, timedelta


# ---------------- GIVEN: do not change ----------------
def curve(marks):
    """Return a new list where every mark m becomes ceil(10 * sqrt(m))."""
    curved = []
    for m in marks:
        curved.append(math.ceil(10 * math.sqrt(m)))
    return curved


def viva_schedule(rolls, start):
    """Print one viva date per roll number, from start, skipping Saturday and Sunday."""
    day = start
    for roll in rolls:
        while day.weekday() >= 5:  # 5 = Saturday, 6 = Sunday
            day = day + timedelta(days=1)
        print(roll, "->", day.strftime("%A, %d %b %Y"))
        day = day + timedelta(days=1)  # next viva on the next day


# ---------------- YOUR WORK ----------------
def generate_marks(count, low, high):
    """Return a list of count random marks between low and high (both included)."""
    res = []
    for i in range (count):
        res.append(random.randint(low, high))
    return res     

rolls = ["24P-0201", "24P-0202", "24P-0203", "24P-0204",
         "24P-0205", "24P-0206", "24P-0207", "24P-0208"]

# TODO 1: call random.seed(25), generate 10 marks between 35 and 100 and print them
random.seed(25)
marks = generate_marks(10, 35, 100)
print("Marks:", marks)

# TODO 2: print the mean and the median of the marks (statistics module)
print(statistics.mean(marks))
print(statistics.median(marks))

# TODO 3: use the given curve() function; print the curved marks and their mean
curved_marks = curve(marks)
print(curved_marks)
print(statistics.mean(curved_marks))

# TODO 4: pick 3 different students from rolls with random.sample, print them,
#         then put them in a random order with random.shuffle and print them again

randomSt = random.sample(rolls, 3)
print(randomSt)
random.shuffle(randomSt)
print(randomSt)
    
# TODO 5: call the given viva_schedule() with your shuffled list and start = date(2026, 10, 16)
viva_schedule(randomSt, date(2026, 10, 16) )
# TODO 6: one student from the whole class (rolls) will help the teacher during the vivas;
#         pick and print this student with random.choice
print(random.choice(rolls))