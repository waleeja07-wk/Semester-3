python_forms = ["24P-0101", "24P-0102", "24P-0103", "24P-0102",
"24P-0104", "24P-0101", "24P-0105"]
ml_forms = ["24P-0103", "24P-0106", "24P-0101", "24P-0107", "24P-0106",
"24P-0105"]
unique_py= set(python_forms)
unique_ml= set(ml_forms)
diff_std = len((unique_py)|(unique_ml))

print("NUMBER OF PYTHON FORMS SUBMITTED:", len(python_forms))
print("NUMBER OF UNIQUE STUDENTS IN PYTHON:", len(unique_py))

print("NUMBER OF ML FORMS SUBMITTED:", len(ml_forms))
print("NUMBER OF UNIQUE STUDENTS IN ML:", len(unique_ml))

print("Students registered in both courses:", unique_py & unique_ml)

print("STUDENTS REGISTERED IN PYTHON BUT NOT IN ML:", (unique_py) - (unique_ml))

print("different students registered in total:", diff_std)
unique_ml.discard("24P-0105")
print(unique_ml)

still_registered = "24P-0105" in unique_py or "24P-0105" in unique_ml
print("24P-0105 still registered in any course:", still_registered)

sorted(python_forms)
sorted(ml_forms)
print(python_forms)
print(ml_forms)

