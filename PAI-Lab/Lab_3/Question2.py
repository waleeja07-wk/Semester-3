as_discipline_issue = False
is_Sports_Student = True
Marks = 57
Attendance = 80

if has_discipline_issue:
    print("Scholarship Denied due to disciplinary record.")
else:
    if Marks >= 90 and Attendance >= 85:
        print("Full Scholarship")
    elif (Marks >= 75 and Attendance >= 80) or (is_Sports_Student and Attendance >= 75):
        print("Half Scholarship")
    else:
        print("No Scholarship granted")
