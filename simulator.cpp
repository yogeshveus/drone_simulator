setupSensors()
	setBotSpeed()
getTime

submitResults

global start_time = -1

setupSensors:
	start_time = sys

setBotspeed : global botspeed = botspeed

global array[x axis ] = ultrasound time
5 10 15 20

get val from arr:
 21
 20
	

dense - 2000

getTime:
	if startime is -1: throw error, print
	iso time now = sys.time()
	current time x axis = iso time now - start_time
    ultrasound time = array[current time x axis]
    blocking wait (ultrasound time)
    return ultrasound time

getCurrentTime:
    return current time x axis
	
submitREsults(count){
	print pass or fail
}