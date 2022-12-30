from tkinter import *
import ctypes

lib = ctypes.CDLL('../libapp.dll')

_py_array = lib.fill_array
_py_array.argtypes = (ctypes.POINTER(ctypes.c_int))
_py_array.restype = None

_py_array2 = lib.filter
_py_array2.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
_py_array.restype = None

def fill_arr(size):
    dst = (ctypes.c_int * size)()
    _py_array(dst, size)
    
    return list(dst, size) 

def output_filter(nums):
    src_len = len(nums)
    dst_len = ctypes.c_int(len(nums))
    src = (ctypes.c_int * src_len)(*nums)
    dst = (ctypes.c_int * dst_len.value)()
    _py_array2(src, src_len, dst, dst_len)

    return list(dst)

window = Tk("lab_12")
window.geometry('500x500+700+300')

first_label = Label(text = "Введите количество чисел Фибоначчи").place(x = 165, y = 64)
second_label = Label(text = "Результат").place(x = 220, y = 115)
first_input = Entry(window, justify = RIGHT)
first_input.place(x = 170, y = 90)
first_output = Entry(window, justify = RIGHT)
first_output.place(x = 170, y = 135)

thirth_label = Label(text = "Выбрать только первое вхождение каждого числа").place(x = 130, y = 198)
fourth_label = Label(text = "Введите элементы массива").place(x = 195, y = 234)
second_input = Entry(window, justify = RIGHT)
second_input.place(x = 170, y = 260)

fifth_label = Label(text = "Первый результат").place(x = 120, y = 300)
output_2_1 = Entry(window, justify = RIGHT)
output_2_1.place(x = 170, y = 325)
sixth_label = Label(text = "Второй результат").place(x = 117, y = 360)
output_2_2 = Entry(window, justify = RIGHT)
output_2_2.place(x = 170, y = 385)

Button(text = "fill", command = lambda : fill_arr(int(first_input.get()))).place(x = 300, y = 130)
Button(text = "go", command = lambda : output_filter(second_input.get())).place(x = 300, y = 325)

window.mainloop()