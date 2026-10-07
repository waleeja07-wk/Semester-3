results = [("24P-0101", 14), ("24P-0102", 9), ("24P-0103", 18),
("24P-0104", 11), ("24P-0105", 18), ("24P-0106", 6), ("24P-0107", 15)]

marks_Sum = 0
highest_marks = 0
top_student = []
below_average = []
marks = []

for r, m in results:
    marks_Sum += m
    if m > highest_marks:
        highest_marks = m
    marks.append(m)
        
Average = marks_Sum / len(results)
        
for r, m in results:
    if m == highest_marks:
        top_student.append(r)

for r, m in results:
    if m < Average:
        below_average.append(r)
     
print("Class Average:",Average)
print("Highest marks:", highest_marks)
print("STUDENTS WHO SCORED HIGHEST MARKS: ")
for s in top_student:
    print(s)
    
print("STUDENTS WHO SCORED BELOW AVERAGE MARKS ARE:", len(below_average)) 
print(below_average)

marks.sort(reverse=True)
print("TOP THREE MARKS:",marks[:3])
