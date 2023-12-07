import subprocess as sbpr
import os
import numpy as np

import time

import matplotlib.pyplot as plt


def getTimes(dat_str, delim):
    
    dat_vals = []
    for ind in range(len(dat_str)-1):
        this_val = dat_str[ind].split(delim)[1]
        dat_vals.append( float(this_val) )
    
    return dat_vals

def formInputStr(master_list):
    
    input_str = ''
    for input_list in master_list:
        for elem in input_list:
            input_str += str(elem) + delim
        input_str += os.linesep
    
    return input_str



time_list = []
time_ind = -1
time_num = 9
num_run = 10


prog_name = "main"
output_mode = 0;
output_filename = "test.dat"
bound_RL = -2
bound_RU = 2
bound_IL = -2
bound_IU = 2
num_R = 500
num_I = 500
num_k = 100
proc_num = 4
compile_flag = 1

cmd_name = "./runPar.bsh"

delim = ','


# TESTING - currently only varies num_k
list_out = 0
list_name = 'test.dat'
list_RL = [-2] 
list_RU = [2]
list_IL = [-2]
list_IU = [2]
list_R = [10, 50, 100, 500, 1000]
list_I = [10, 50, 100, 500, 1000]
list_k = [10, 25, 50, 100, 500, 1000]
list_num = 9

master_arr = np.meshgrid(list_out, list_name, list_RL, list_RU, list_IL, list_IU, list_R, list_I, list_k)
master_arr = np.array(master_arr).T.reshape(-1, list_num)

master_list = []
for ind in range( master_arr.shape[0] ):
    '''
    input_list = [output_mode, output_filename, bound_RL, bound_RU, 
                    bound_IL, bound_IU, num_R, num_I, num_k]
    '''
    input_list = list(master_arr[ind, :])
    master_list.append(input_list)

input_str = formInputStr(master_list)
input_bytes = bytes(input_str, 'utf-8')


#%%
run_arr = np.zeros([len(master_list), time_num, num_run])

t00 = time.time()
for itr in range(num_run):
    print(itr)
    # Form Input
    arg_list = [cmd_name, prog_name, proc_num, compile_flag]
    for ind, elem in enumerate(arg_list):
        arg_list[ind] = str(elem)
    
    # Run Code
    tC_0 = time.time()
    #test = sbpr.run(arg_list, capture_output=True)
    print("Running")
    proc = sbpr.Popen(arg_list, stdin=sbpr.PIPE, stdout=sbpr.PIPE)
    print("Sending")
    output, errs = proc.communicate(input=input_bytes)
    tC_f = time.time()
    tC_E = tC_f - tC_0
    time_list.append(tC_E)
    
    print(output.decode())
    
    # Parse Output
    #TODO: rewrite to handle output of full set (?)
    dat_raw = output.decode()
    dat_list = dat_raw.split('\n')
    dat_list.pop(-1) # Remove empty entry
    
    for ind, elem in enumerate(dat_list):
        dat_list[ind] = elem.split(" ")
        run_arr[ind, :, itr] = getTimes(dat_list[ind], delim='---')
    
tFF = time.time()
tR = tFF - t00

mean_arr = np.mean(run_arr, axis=2)
#dat_arr = np.array(dat_list[1:time_ind], dtype=float) # Get Mandelbrot set



print(output.decode())


if (compile_flag):
    print("Compiled")
else:
    print("Did not compile")
print("Run time: " + str(tC_E))
print("Total Time: " + str(tR))    
print(dat_list[time_ind])

plt.plot(mean_arr[:, 1])


#%% Plot Results

im_dat = np.exp( -np.abs(dat_arr) )


real_ax = np.linspace(bound_RL, bound_RU, num_R)
imag_ax = np.linspace(bound_IL, bound_IU, num_I)

plt.imshow(im_dat)




#%% Numpy implementation


tP_0 = time.time()
real_vec = np.linspace(bound_RL, bound_RU, num_R)
imag_vec = 1.j*np.linspace(bound_IL, bound_IU, num_I)

coord_grid = np.meshgrid(real_vec, imag_vec)
c_grid = coord_grid[0] + coord_grid[1]

z_grid = np.zeros([num_R, num_I], dtype=np.float64)

for itr in range(num_k):
    z_grid = z_grid**2 + c_grid


tP_f = time.time()
tP_E = tP_f - tP_0
time_list.append(tP_E)    

a_grid = abs(z_grid)
p_grid = np.exp(-a_grid)
plt.imshow(p_grid)


#%% Testing


test = np.array([[1, 2, 3], [1, 5, 3], [7, 8, 9]])
test2 = test[:, [0, 2]]

test3 = (test2 == [1, 3])
test4 = test[ test3.all(axis=1), : ]


