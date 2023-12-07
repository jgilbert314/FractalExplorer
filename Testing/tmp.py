import subprocess as sbpr
import os


input_list = [r'Arg 1a---Arg 1b' + os.linesep, r'Arg 2a---Arg 2b' + os.linesep]
input_byt = [bytes(elem, 'ascii') for elem in input_list]

input_str = ''
for elem in input_list:
    input_str += elem
input_bytes = bytes(input_str, 'ascii')

outs = []
errs = []
with sbpr.Popen(["./a.out"], bufsize=1, stdin=sbpr.PIPE, stdout=sbpr.PIPE) as proc:
    print("Communicating")
    
    outs, _ = proc.communicate(input=input_bytes)
    
    '''
    for msg in input_byt:
        this_buff = proc.stdin.write(msg)
    proc.stdin.close()
    
    for ind, line in enumerate(proc.stdout):
        print('Num ' + str(ind) + ': ' + str(line))
    '''
