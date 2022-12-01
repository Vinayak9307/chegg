def main():
    input_file_name = 'AtlantaTemps2017.csv'

    try:
        input_file = open(input_file_name,'r')
    except FileNotFoundError:
        print('Cannot find ' + input_file_name + ' file in the current directory.')

    data = input_file.readlines()

    input_file.close()

    check_highest_temp(data)
    check_lowest_temp(data)
    check_lowest_high_temp(data)
    check_highest_low_temp(data)
    check_average_high_temp(data)
    check_average_low_temp(data)
    check_low_temp_below_threshold(data)
    check_high_temp_below_threshold(data)


def check_highest_temp(data):
    highest = -273
    highest_date = ""
    for day in data:
        day_data = day.split(',')
        if int(day_data[1]) > highest:
            highest = int(day_data[1])
            highest_date = day_data[0]
        
    print(str(highest) + ' was the highest temperature of the year and it occured on ' + highest_date)

def check_lowest_temp(data):
    lowest = 273
    lowest_date = ""
    for day in data:
        day_data = day.split(',')
        if int(day_data[2]) < lowest:
            lowest = int(day_data[2])
            lowest_date = day_data[0]
        
    print(str(lowest) + ' was the lowest temperature of the year and it occured on ' + lowest_date)

def check_lowest_high_temp(data):
    lowest_high = 273
    lowest_high_date = ""
    for day in data:
        day_data = day.split(',')
        if int(day_data[1]) < lowest_high:
            lowest_high = int(day_data[1])
            lowest_high_date = day_data[0]
        
    print(str(lowest_high) + ' was the lowest high temperature of the year and it occured on ' + lowest_high_date)

def check_highest_low_temp(data):
    highest_low = -273
    highest_low_date = ""
    for day in data:
        day_data = day.split(',')
        if int(day_data[2]) > highest_low:
            highest_low = int(day_data[2])
            highest_low_date = day_data[0]
        
    print(str(highest_low) + ' was the highest low temperature of the year and it occured on ' + highest_low_date)

def check_average_high_temp(data):
    high_temp_sum = 0
    for day in data:
        day_data = day.split(',')
        high_temp_sum = high_temp_sum + int(day_data[1])
    
    average_high_temp = high_temp_sum / len(data)
    print(str(average_high_temp) + ' is the average high temperature of the year 2017')

def check_average_low_temp(data):
    low_temp_sum = 0
    for day in data:
        day_data = day.split(',')
        low_temp_sum = low_temp_sum + int(day_data[2])
    
    average_low_temp = low_temp_sum / len(data)
    print(str(average_low_temp) + ' is the average low temperature of the year 2017')


def check_low_temp_below_threshold(data):
    print('Enter a threshold value to check the number of days on which temperature was lower than threshold: ')
    threshold = float(input())
    day_count = 0
    for day in data:
        day_data = day.split(',')
        if int(day_data[2]) < threshold:
            day_count = day_count + 1
    print('There are ' + str(day_count) + ' days when temperature was lower than threshold')

def check_high_temp_below_threshold(data):
    print('Enter a threshold value to check the number of days on which temperature was high than threshold: ')
    threshold = float(input())
    day_count = 0
    for day in data:
        day_data = day.split(',')
        if int(day_data[1]) > threshold:
            day_count = day_count + 1
    print('There are ' + str(day_count) + ' days when temperature was high than threshold')


main()