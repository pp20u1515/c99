import tkinter as tk
import ctypes

lib = ctypes.CDLL("app.so")

_py_array = lib.fill_array
_py_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_py_array.restype = None

_py_array2 = lib.filter
_py_array2.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
_py_array.restype = ctypes.c_int

def fill_arr(size):
    dst = (ctypes.c_int * size)()
    _py_array(dst, size)
    first_output.delete(0, tk.END)
    first_output.insert(0, list(dst)) 

def py_filterr(nums):
    size = len(nums)
    src = (ctypes.c_int * size)(*nums)
    dst = (ctypes.c_int * size)()
    dst_len = _py_array2(src, size, dst)

    return list(dst), dst_len

def output_filter(array):
    string = array.split(' ')
    
    try:
        string = list(map(int, string))
        temp_array, size = py_filterr(string)
        
        line = ''
        count = 0
        
        while count < size.value:
            line += str(temp_array[count]) + ' '
            count += 1
            
        output_2_1.delete(0, tk.END)
        output_2_1.insert(0, line)
    except:
        output_2_1.delete(0, tk.END)
        output_2_1.insert(0, 'Неправильный ввод!')

window = tk.Tk()
window.geometry('500x500+700+300')

first_label = tk.Label(text = "Введите количество чисел Фибоначчи").place(x = 165, y = 64)
second_label = tk.Label(text = "Результат").place(x = 220, y = 115)
first_input = tk.Entry(window, justify = tk.RIGHT)
first_input.place(x = 170, y = 90)
first_output = tk.Entry(window, justify = tk.RIGHT)
first_output.place(x = 170, y = 135)

thirth_label = tk.Label(text = "Выбрать только первое вхождение каждого числа").place(x = 130, y = 198)
fourth_label = tk.Label(text = "Введите элементы массива").place(x = 195, y = 234)
second_input = tk.Entry(window, justify = tk.RIGHT)
second_input.place(x = 170, y = 260)

fifth_label = tk.Label(text = "Результат").place(x = 120, y = 300)
output_2_1 = tk.Entry(window, justify = tk.RIGHT)
output_2_1.place(x = 170, y = 325)

tk.Button(text = "fill", command = lambda : fill_arr(int(first_input.get()))).place(x = 350, y = 130)
tk.Button(text = "go", command = lambda : output_filter(str(second_input.get()))).place(x = 350, y = 325)

window.mainloop()
