from Service.service import *
import tkinter as tk

class GUI :

    def __init__(self, srv_stud, srv_sub, srv_grd, undo_srv):
        self.__srv_stud = srv_stud
        self.__srv_sub = srv_sub
        self.__srv_grd= srv_grd
        self.__undo_srv = undo_srv
        self.root = tk.Tk()
        self.canvas = tk.Canvas(self.root, height = 600, width = 1000)
        self.canvas.pack()
        self.frame = tk.Frame(self.root, bg = "white")
        self.frame.place(relx=0, rely=0, relheight = 0.25, relwidth = 1)
        self.cmd_frame = tk.Frame(self.root, bg = "white")
        self.cmd_frame.place(relx =0.25 , rely =0.25, relheight = 0.5, relwidth = 0.75)
        self.error_frame = tk.Frame(self.root, bg="white")
        self.error_frame.place(relx = 0.25, rely = 0.75, relheight = 0.25, relwidth = 0.75)
        self.error_text = tk.Label(self.error_frame, height=100, width=100, anchor="nw", padx=10, text="", font="bold",bg="white")
        self.error_text.place(relx=0.25, rely=0, relwidth=1, relheight=1)
        self.Manage_button = tk.Button(self.frame, text="Manage", bg = "dark blue",fg="white",
                                       command = self.get_manage_buttons)
        self.Manage_button.place(relx = 0, rely=0, relheight = 1, relwidth = 0.2)
        self.List_button = tk.Button(self.frame, text="List", bg="dark blue", fg="white", command = self.get_list_buttons)
        self.List_button.place(relx=0.2, rely=0, relheight=1, relwidth=0.2)
        self.Search_button = tk.Button(self.frame, text="Search", bg="dark blue", fg="white", command =self.get_search_buttons)
        self.Search_button.place(relx=0.4, rely=0, relheight=1, relwidth=0.2)
        self.Undo_button = tk.Button(self.frame, text="Undo", bg="dark blue", fg="white", command =self.gui_undo)
        self.Undo_button.place(relx=0.6, rely=0, relheight=1, relwidth=0.2)
        self.Redo_button = tk.Button(self.frame, text="Redo", bg="dark blue", fg="white", command = self.gui_redo)
        self.Redo_button.place(relx=0.8, rely=0, relheight=1, relwidth=0.2)
        self.root.mainloop()

    def clear_text(self):
        try :
            self.cmd_frame.destroy()
            self.buttons_frame.destroy()
            self.error_text["text"] = ""
            self.label_display["text"] = ""
        except Exception :
            pass

    def get_manage_buttons(self):
        self.clear_text()
        self.buttons_frame = tk.Frame(self.root, bg="white")
        self.buttons_frame.place(relx=0, rely=0.25, relheight=0.75, relwidth=0.25)
        self.Add_student_button = tk.Button(self.buttons_frame, text="Add a student", fg="white",
            bg="dark blue", command = self.add_student_params)
        self.Add_student_button.place(relx=0, rely= 0, relheight= 0.12, relwidth = 1)
        self.Add_subject_button = tk.Button(self.buttons_frame, text="Add a subject", fg="white",
            bg="dark blue", command = self.add_subject_params)
        self.Add_subject_button.place(relx=0, rely=0.12, relheight=0.12, relwidth=1)
        self.Remove_student_button = tk.Button(self.buttons_frame, text="Remove a student", fg="white",
            bg="dark blue", command = self.remove_student_params)
        self.Remove_student_button.place(relx=0, rely=0.24, relheight=0.12, relwidth=1)
        self.Remove_subject_button = tk.Button(self.buttons_frame, text="Remove a subject", fg="white",
            bg="dark blue", command = self.remove_subject_params)
        self.Remove_subject_button.place(relx=0, rely=0.36, relheight=0.12, relwidth=1)
        self.Grade_student_button = tk.Button(self.buttons_frame, text="Grade a student", fg="white",
            bg="dark blue", command = self.grade_student_params)
        self.Grade_student_button.place(relx=0, rely=0.48, relheight=0.12, relwidth=1)
        self.Update_student_button = tk.Button(self.buttons_frame, text="Update a student", fg="white",
            bg="dark blue", command = self.update_student_params)
        self.Update_student_button.place(relx=0, rely=0.6, relheight=0.12, relwidth=1)
        self.Update_subject_button = tk.Button(self.buttons_frame, text="Update a subject", fg="white",
            bg="dark blue", command =self.update_subject_params)
        self.Update_subject_button.place(relx=0, rely=0.72, relheight=0.12, relwidth=1)

    def create_frame(self, need_name, text1, text2, cmd):
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.id = tk.Label(self.cmd_frame, height=50, width=100, anchor="n", padx=10,
                                   text=text1, bg="orange")
        self.id.place(relwidth=1, relheight=0.1)
        self.write_id = tk.Entry(self.cmd_frame)
        self.write_id.place(relx=0, rely=0.1, relwidth=1, relheight=0.1)
        if need_name == True :
            self.name = tk.Label(self.cmd_frame, height=50, width=100, anchor="n", padx=10,
                                         text=text2, bg="orange")
            self.name.place(rely=0.2, relwidth=1, relheight=0.1)
            self.write_name = tk.Entry(self.cmd_frame)
            self.write_name.place(relx=0, rely=0.3, relwidth=1, relheight=0.05)
            self.enter_button = tk.Button(self.cmd_frame, text="Enter", bg="orange", command=cmd)
            self.enter_button.place(relx=0, rely=0.40, relwidth=1, relheight=0.1)
        else :
            self.enter_button = tk.Button(self.cmd_frame, text="Enter", bg="orange", command=cmd)
            self.enter_button.place(relx=0, rely=0.2, relwidth=1, relheight=0.1)

    def add_student_params(self):
        self.create_frame(True, "Please introduce the id of the student", "Please introduce the name of the student",
                          self.gui_add_student)

    def gui_add_student(self):
        stud_id = self.write_id.get()
        name = self.write_name.get()
        stud = Clients(stud_id, name)
        try :
            self.__srv_stud.add(stud)
        except validerror as valide:
            self.error_text["text"] = str(valide)
        except repoerror as re:
            self.error_text["text"] = str(re)
        self.cmd_frame.destroy()
        self.buttons_frame.destroy()

    def add_subject_params(self):
        self.create_frame(True, "Please introduce the id of the subject", "Please introduce the name of the subject",
                          self.gui_add_subject)

    def gui_add_subject(self):
        sub_id = self.write_id.get()
        name = self.write_name.get()
        sub = subject(sub_id, name)
        try :
            self.__srv_sub.add(sub)
        except validerror as valide:
            self.error_text["text"] = str(valide)
        except repoerror as re:
            self.error_text["text"] = str(re)
        self.cmd_frame.destroy()
        self.buttons_frame.destroy()

    def remove_student_params(self):
        self.create_frame(False, "Please introduce the id of the student", "", self.gui_remove_student)

    def gui_remove_student(self):
        stud_id = self.write_id.get()
        stud = student(stud_id, None)
        try :
            self.__srv_grd.remove_by_student(stud)
        except validerror as valide:
            self.error_text["text"] = str(valide)
        except repoerror as re:
            self.error_text["text"] = str(re)
        self.cmd_frame.destroy()
        self.buttons_frame.destroy()

    def remove_subject_params(self):
        self.create_frame(False, "Please introduce the id of the subject", "", self.gui_remove_subject)

    def gui_remove_subject(self):
        sub_id = self.write_id.get()
        sub = subject(sub_id, None)
        try :
            self.__srv_grd.remove_by_subject(sub)
        except validerror as valide:
            self.error_text["text"] = str(valide)
        except repoerror as re:
            self.error_text["text"] = str(re)
        self.cmd_frame.destroy()
        self.buttons_frame.destroy()

    def grade_student_params(self):
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.stud_id = tk.Label(self.cmd_frame, height=50, width=100, anchor="n", padx=10,
                           text="Please introduce the id of the student", bg="orange")
        self.stud_id.place(relwidth=1, relheight=0.1)
        self.write_stud_id = tk.Entry(self.cmd_frame)
        self.write_stud_id.place(relx=0, rely=0.1, relwidth=1, relheight=0.1)
        self.sub_id = tk.Label(self.cmd_frame, height=50, width=100, anchor="n", padx=10,
                             text="Please introduce the id of the subject", bg="orange")
        self.sub_id.place(rely=0.2, relwidth=1, relheight=0.1)
        self.write_sub_id = tk.Entry(self.cmd_frame)
        self.write_sub_id.place(relx=0, rely=0.3, relwidth=1, relheight=0.05)
        self.grade = tk.Label(self.cmd_frame, height=50, width=100, anchor="n", padx=10,
                             text="Please introduce the grade", bg="orange")
        self.grade.place(rely = 0.4, relwidth = 1, relheight = 0.1)
        self.write_grade = tk.Entry(self.cmd_frame)
        self.write_grade.place(relx = 0, rely = 0.5, relwidth =1, relheight = 0.05 )
        self.enter_button = tk.Button(self.cmd_frame, text="Enter", bg="orange", command=self.gui_add_grade)
        self.enter_button.place(relx=0, rely=0.6, relwidth=1, relheight=0.1)

    def gui_add_grade(self):
        stud_id = self.write_stud_id.get()
        sub_id = self.write_sub_id.get()
        val = self.write_grade.get()
        stud = student(stud_id, None)
        sub = subject(sub_id, None)
        try :
            val = float(val)
            grd = grade(stud, sub, val)
            self.__srv_grd.add(grd)
        except validerror as valide:
            self.error_text["text"] = str(valide)
        except repoerror as re:
            self.error_text["text"] = str(re)
        except ValueError :
            self.error_text["text"] = "Invalid value for grade !"
        self.cmd_frame.destroy()
        self.buttons_frame.destroy()

    def update_student_params(self):
        self.create_frame(True, "Please introduce the id of the student",
                          "Please introduce the new name of the student", self.gui_update_student)

    def gui_update_student(self):
        stud_id = self.write_id.get()
        name = self.write_name.get()
        stud = student(stud_id, name)
        try:
            self.__srv_stud.update(stud,name)
        except validerror as valide:
            self.error_text["text"] = str(valide)
        except repoerror as re:
            self.error_text["text"] = str(re)
        self.cmd_frame.destroy()
        self.buttons_frame.destroy()

    def update_subject_params(self):
        self.create_frame(True, "Please introduce the id of the subject",
                          "Please introduce the new name of the subject", self.gui_update_subject)

    def gui_update_subject(self):
        sub_id = self.write_id.get()
        name = self.write_name.get()
        sub = subject(sub_id, name)
        try:
            self.__srv_sub.update(sub,name)
        except validerror as valide:
            self.error_text["text"] = str(valide)
        except repoerror as re:
            self.error_text["text"] = str(re)
        self.cmd_frame.destroy()
        self.buttons_frame.destroy()

    def get_list_buttons(self):
        self.clear_text()
        self.buttons_frame = tk.Frame(self.root, bg="white")
        self.buttons_frame.place(relx=0, rely=0.25, relheight=0.75, relwidth=0.25)
        self.List_student_button = tk.Button(self.buttons_frame, text="List of students", fg="white",
                                            bg="dark blue", command=self.gui_list_students)
        self.List_student_button.place(relx=0, rely=0, relheight=0.12, relwidth=1)
        self.List_subject_button = tk.Button(self.buttons_frame, text="List of subjects", fg="white",
                                            bg="dark blue", command=self.gui_list_subjects)
        self.List_subject_button.place(relx=0, rely=0.12, relheight=0.12, relwidth=1)
        self.List_grade_button = tk.Button(self.buttons_frame, text="List of grades", fg="white",
                                               bg="dark blue", command=self.gui_list_grades)
        self.List_grade_button.place(relx=0, rely=0.24, relheight=0.12, relwidth=1)
        self.Failing_students_button = tk.Button(self.buttons_frame, text="List of failing students", fg="white",
                                               bg="dark blue", command=self.gui_failing_students)
        self.Failing_students_button.place(relx=0, rely=0.36, relheight=0.12, relwidth=1)
        self.Best_students_button = tk.Button(self.buttons_frame, text="List of best students", fg="white",
                                              bg="dark blue", command=self.gui_best_students)
        self.Best_students_button.place(relx=0, rely=0.48, relheight=0.12, relwidth=1)

    def gui_list_students(self):
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx = 0, rely= 0, relheight = 1, relwidth= 1)
        text=""
        for stud in self.__srv_stud.get_students() :
            text = text + str(stud) +'\n'
        if len(self.__srv_stud.get_students()) == 0 :
            text = "There are no students in the list."
        self.label_display["text"] = text

    def gui_list_subjects(self):
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx=0, rely=0, relheight=1, relwidth=1)
        text = ""
        for sub in self.__srv_sub.get_subjects():
            text = text + str(sub) + '\n'
        if len(self.__srv_sub.get_subjects()) == 0 :
            text = "There are no subjects in the list."
        self.label_display["text"] = text

    def gui_list_grades(self):
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx=0, rely=0, relheight=1, relwidth=1)
        text = ""
        for grd in self.__srv_grd.return_grades():
            text = text + str(grd) + '\n'
        if len(self.__srv_sub.get_subjects()) == 0 :
            text = "There are no grades in the list."
        self.label_display["text"] = text

    def gui_failing_students(self):
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx=0, rely=0, relheight=1, relwidth=1)
        text = ""
        l = self.__srv_grd.failing_students()
        for i in range(len(l)):
            name_stud = l[i]["student"].get_name()
            stud_id = l[i]["student"].get_stud_id()
            name_sub = l[i]["subject"].get_name()
            sub_id = l[i]["subject"].get_sub_id()
            average = l[i]["average"]
            text = text +"The student " + str(name_stud) + " with id : " + str(stud_id) +\
                   " failed at object " + str(name_sub) + " with id : " + str(sub_id) + " having " + str(average)
            text = text +"\n"
        self.label_display["text"] = text

    def gui_best_students(self):
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx=0, rely=0, relheight=1, relwidth=1)
        text = ""
        l = self.__srv_grd.best_students()
        for i in range(len(l)):
            stud = l[i]["student"]
            name_stud = stud.get_name()
            stud_id = stud.get_stud_id()
            average = l[i]["average"]
            text = text+"The student " + str(name_stud) + " with id : " + str(stud_id) \
                   + " has the average : "+ str(average)
            text = text +"\n"
        self.label_display["text"] = text

    def get_search_buttons(self):
        self.clear_text()
        self.buttons_frame = tk.Frame(self.root, bg="white")
        self.buttons_frame.place(relx=0, rely=0.25, relheight=0.75, relwidth=0.25)
        self.Search_student_id_button = tk.Button(self.buttons_frame, text="Search a student after id", fg="white",
                                            bg="dark blue", command=self.search_student_id_params)
        self.Search_student_id_button.place(relx=0, rely=0, relheight=0.12, relwidth=1)
        self.Search_student_name_button = tk.Button(self.buttons_frame, text="Search a student after name", fg="white",
                                            bg="dark blue", command=self.search_student_name_params)
        self.Search_student_name_button.place(relx=0, rely=0.12, relheight=0.12, relwidth=1)
        self.Search_subject_id = tk.Button(self.buttons_frame, text="Search a subject after id", fg="white",
                                               bg="dark blue", command=self.search_subject_id_params)
        self.Search_subject_id.place(relx=0, rely=0.24, relheight=0.12, relwidth=1)
        self.Search_subject_name = tk.Button(self.buttons_frame, text="Search a subject after name", fg="white",
                                               bg="dark blue", command=self.search_subject_name_params)
        self.Search_subject_name.place(relx=0, rely=0.36, relheight=0.12, relwidth=1)

    def search_student_id_params(self):
        self.create_frame(False, "Please introduce the id of the student ","",self.gui_search_student_id)

    def gui_search_student_id(self):
        pattern = self.write_id.get()
        self.cmd_frame.destroy()
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx=0, rely=0, relheight=1, relwidth=1)
        text = ""
        l = self.__srv_stud.search_partial_student("ID", pattern)
        for i in range(len(l)):
            text = text+str(l[i])+"\n"
        if len(l) == 0:
            text="There are no such students in the list."
        self.label_display["text"] = text

    def search_student_name_params(self):
        self.create_frame(False, "Please introduce the name of the student ","",self.gui_search_student_name)

    def gui_search_student_name(self):
        pattern = self.write_id.get()
        self.cmd_frame.destroy()
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx=0, rely=0, relheight=1, relwidth=1)
        text = ""
        l = self.__srv_stud.search_partial_student("name", pattern)
        for i in range(len(l)):
            text = text+str(l[i])+"\n"
        if len(l) == 0:
            text="There are no such students in the list."
        self.label_display["text"] = text

    def search_subject_id_params(self):
        self.create_frame(False, "Please introduce the id of the subject ","",self.gui_search_subject_id)

    def gui_search_subject_id(self):
        pattern = self.write_id.get()
        self.cmd_frame.destroy()
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx=0, rely=0, relheight=1, relwidth=1)
        text = ""
        l = self.__srv_sub.search_partial_subject("ID", pattern)
        for i in range(len(l)):
            text = text+str(l[i])+"\n"
        if len(l) == 0:
            text="There are no such subjects in the list."
        self.label_display["text"] = text

    def search_subject_name_params(self):
        self.create_frame(False, "Please introduce the name of the subject ","",self.gui_search_subject_name)

    def gui_search_subject_name(self):
        pattern = self.write_id.get()
        self.cmd_frame.destroy()
        self.clear_text()
        self.cmd_frame = tk.Frame(self.root, bg="white")
        self.cmd_frame.place(relx=0.25, rely=0.25, relheight=0.5, relwidth=0.75)
        self.label_display = tk.Label(self.cmd_frame, bg="white")
        self.label_display.place(relx=0, rely=0, relheight=1, relwidth=1)
        text = ""
        l = self.__srv_sub.search_partial_subject("name", pattern)
        for i in range(len(l)):
            text = text+str(l[i])+"\n"
        if len(l) == 0:
            text="There are no such subjects in the list."
        self.label_display["text"] = text

    def gui_undo(self):
        self.clear_text()
        try :
            self.__undo_srv.undo()
        except validerror as valide:
            self.error_text["text"] = str(valide)

    def gui_redo(self):
        self.clear_text()
        try :
            self.__undo_srv.redo()
        except validerror as valide:
            self.error_text["text"] = str(valide)











