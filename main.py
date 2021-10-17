import os
import sys

if len(sys.argv) != 2:
    sys.exit("Please specify input file extension and output file extension!! Ex: python main.py inp out")
root_dir = "./" + sys.argv[1]
for folder in os.listdir(root_dir):
    if os.path.isdir(os.path.join(root_dir, folder)):
        have_inp_and_out = 0
        for file_name in os.listdir(os.path.join(root_dir, folder)):
            if file_name.endswith(".cpp"):
                with open(os.path.join(root_dir, folder, file_name), 'r') as file:
                    content = file.read()
                if file_name == "main.cpp" :
                    with open(folder+".cpp", 'w') as file:
                        file.write(content)
                else:
                    lname = folder + file_name[0]
                    if file_name[1] != '_':
                        lname = lname + file_name[1]
                    with open(lname+".cpp",'w') as file:
                        file.write(content)
print("Done !")