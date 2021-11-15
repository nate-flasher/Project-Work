flightsD={"Delta":{1102:[["IND",1850],["MDW",1955]],
                   1096:[["PHX",900],["MDW",1255]],
                   1445:[["ATL",1135],["LAX",1810]],
                   1776:[["PHL",1350],["RAP",1610]],
                   1226:[["PHX",950],["MDW",1345]],
                   1885:[["ATL",1305],["LAX",2000]],
                   1009:[["MDW",1850],["IND",1955]],
                   9001:[["MDW",2145],["IND",2255]]},
          "Southwestern":{1111:[["SAT",430],["MDW",825]],
                          2121:[["MDW",430],["SAT",825]],
                          4335:[["PHX",450],["MDW",745]],
                          1102:[["MDW",1100],["PHX",1450]]},
          "American":{7765:[["IND",1850],["CHA",2105]],
                   2133:[["BNA",900],["IND",1115]],
                   3321:[["HOU",1335],["ATL",1615]],
                   2100:[["BNA",900],["IND",1115]],
                   4311:[["HOU",905],["ATL",1255]],
                   5577:[["ATL",1100],["HOU",1350]],
                   1102:[["BNA",1100],["HOU",1450]]}  }


#Contains the number of each problem you will test when you press run
#(modify as desire)
test=[4]



#Prob 1
def reportAllFlightsFromTo(flightsD,fromCity,toCity):
    print(fromCity.rjust(10),toCity.rjust(4))
    print("NUM".rjust(5)+"DEP".rjust(5)+"RET".rjust(5)+"  "+"AIRLINE".rjust(5))
    for airline in flightsD:
        for flightNum in flightsD[airline]:
            if flightsD[airline][flightNum][0][0]==fromCity and flightsD[airline][flightNum][1][0]==toCity:
                print(str(flightNum).rjust(5)+str(flightsD[airline][flightNum][0][1]).rjust(5)+str(flightsD[airline][flightNum][1][1]).rjust(5)+str(airline).rjust(7))
if 1 in test:
    print("PROBLEM 1\n")
    reportAllFlightsFromTo(flightsD,"PHX","MDW")
    print()
    reportAllFlightsFromTo(flightsD,"MDW","IND")
    print("\n\n\n")



#Prob 2
NeedDST=["IND","PHX","ATL","HOU","BNA","SAT","LAX","PHL"]
def updateDaylightSavingsTimes(flightsD,AirportsNeedingDST,Increment):
    for airline in flightsD:
        for flightNum in flightsD[airline]:
            for lst in flightsD[airline][flightNum]:
                if lst[0] in AirportsNeedingDST:
                    lst[1]+=Increment
    

if 2 in test:
    print("PROBLEM 2\n")
    print(flightsD,"\n")
    updateDaylightSavingsTimes(flightsD,NeedDST,100)
    print(flightsD)
    print("\n\n\n")



#Prob 3
def createNewFlight(flightsD,airline,flight,depCity,depTime,arrCity,arrTime):
    flightsD.update({airline:{flight:[[depCity,depTime],[arrCity,arrTime]]}})
        

if 3 in test:
    print("PROBLEM 3\n")
    print(flightsD,"\n")
    createNewFlight(flightsD,"JET BLUE",1010,"IND",605,"MDW",705)
    print(flightsD)
    print("\n\n\n")



#Prob 4    
def reportFlightsByAirlineByFlightNumArrivePriorTo(flightsD,ArrivalTime):
    airlines=[]
    for air in flightsD.keys():
        airlines.append(air)
    airlines.sort()

    test=[]

    for airline in airlines:
        test=[]
        print("%15s %5s %5s %5s" % (airline,"NUM","ARR","TIME"))
        for flight in flightsD[airline].keys():
            if flightsD[airline][flight][1][1]<ArrivalTime:
                test.append((flight,flightsD[airline][flight][1][0],flightsD[airline][flight][1][1]))
        test.sort()
        for item in test:
            print("%15s %5s %5s %5s" % ("",str(item[0]),str(item[1]),str(item[2])))

if 4 in test:
    print("PROBLEM 4\n")
    reportFlightsByAirlineByFlightNumArrivePriorTo(flightsD,1200)
    print("\n\n\n")
    reportFlightsByAirlineByFlightNumArrivePriorTo(flightsD,1600)
    print("\n\n\n")



#Prob 5
def reportFlightsBySortedDepartureCityBySortedDepartureTime(flightsD):
    pass

if 5 in test:
    print("PROBLEM 5\n")
    reportFlightsBySortedDepartureCityBySortedDepartureTime(flightsD)
    print("\n\n\n")



#Prob 6
def reportFlightsSameAirlineRoundTrip(flightsD,fromCity,toCity):
    pass

if 6 in test:
    print("PROBLEM 6\n")
    reportFlightsSameAirlineRoundTrip(flightsD,"IND","MDW")
    print("\n\n\n")
    reportFlightsSameAirlineRoundTrip(flightsD,"PHX","MDW")
    print("\n\n\n")                      
    reportFlightsSameAirlineRoundTrip(flightsD,"MDW","PHX")
    print("\n\n\n")                      



#Prob 7
def reportFlightNumDupes(flightsD):
    pass

if 7 in test:
    print("PROBLEM 7\n")
    print(reportFlightNumDupes(flightsD))
    print("\n\n\n")                      



#Prob 8
def fromToVia(flightsD,fromCity,toCity):
    pass

if 8 in test:
    print("PROBLEM 8\n")
    fromToVia(flightsD,"IND","MDW")
    print("\n\n\n")
    fromToVia(flightsD,"BNA","MDW")
    print("\n\n\n")                   

            
            
