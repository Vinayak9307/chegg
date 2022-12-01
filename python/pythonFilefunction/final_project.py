	def main():

    #checking the input file

    while True:
        input_file_name = input('Enter the input file name: ')
        try:
            input_file = check_file(input_file_name , 0)
        except FileNotFoundError:
            print('\nERROR -- There is an issue with file ' + input_file_name)
        else:
            break
    
    # checking the output file

    while True:
        output_file_name = input('\nEnter the output file name: ')
        try:
            output_file = check_file(output_file_name,1)
        except:
            print('\nERROR -- There is an issue with file ' + output_file_name)
        else:
            break
    
    #reading data from input file and storing it in a list
    ip_Address_List = input_file.readlines()

    #closing input file 
    input_file.close()

    #this is the suspect_ip_list at start it is empty
    suspect_ip_list = []

    #checking for suspects in the ip_Address_List
    for line in ip_Address_List:
        data = line.split(',')
        if(check_suspect(data[0])):
            suspect_ip_list.append(line)

    #Printing the output
    print_output(len(ip_Address_List) , suspect_ip_list , output_file)
    output_file.close()

    print('Program complete!')



def check_suspect(ip_Addres):
#this function takes a single parameter a string ipaddress then split 
#that with respect to (.) then it compare the starting values with the 
#given values and return true if it finds one
    octets = ip_Addres.split('.')

    if(octets[0] == '168' and octets[1] == '193'):
        return True
    if(octets[0] == '224' and octets[1] == '174'):
        return True
    if(octets[0] == '233' and octets[1] == '012'):
        return True

#if any octet doesn't match the suspect condition return false
    return False


def check_file(file_name , n):

#this function takes in two parameter 1 is file_name and other is operation
# n = 0 means it is an input operation 
# n = 1 means it is an output operation

    if(n==0):
        try:
            input_file = open(file_name,'r')
            return input_file
        except FileNotFoundError:
            raise FileNotFoundError

    else:
        try:
            output_file = open(file_name,'w')
            return output_file
        except:
            raise IOError

def print_output(total_records , suspect_ip_list , output_file):
    print()     #adding a newLine

    write_to_file('Output Report\n',output_file)
    write_to_file('-------------\n',output_file)
    write_to_file('The total number of records in the file is: '+str(total_records)+'\n',output_file)
    
    total_suspects = len(suspect_ip_list)
    write_to_file('\nThe number of suspect IP addresses is: '+str(total_suspects)+'\n',output_file)

    suspect_percentage = total_suspects * 100 / total_records
    write_to_file('\nThe percentage of suspect IP addresses is: ' + '%.3f' % suspect_percentage +'\n',output_file)
    write_to_file('\nSuspect IP Addresses\n',output_file)
    write_to_file('--------------------\n',output_file)

    for suspect in suspect_ip_list:
        data = suspect.split(',')
        write_to_file('IP Address = '+data[0]+'  Date and Time = '+ data[1]+'\n' , output_file)

#this function is used to write string on screen as well as on file
def write_to_file(str,output_file):
    print(str , end='')
    output_file.write(str)


main()
