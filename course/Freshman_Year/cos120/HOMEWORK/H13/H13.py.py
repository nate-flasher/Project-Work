def get12HourTime(originalTime):
    timeDict={13:1,14:2,15:3,16:4,17:5,18:6,19:7,20:8,21:9,22:10,23:11}
    temp = str(originalTime)
    time = []
    for character in temp:
        time.append(character)
    
    
    if originalTime >= 1300:
        zeroCase = '00' if (str(int(str(originalTime)[2:])) == '0') else str(int(str(originalTime)[2:]))
        return str(timeDict[int(str(originalTime)[:2])]) + ':' + zeroCase + ' pm'
                                                              

    else:
        zeroCase = '00' if (str(int(str(originalTime)[1:])) == '0') else str(int(str(originalTime)[1:]))
        return str(int(str(originalTime)[:1])) + ':' + zeroCase + ' am'
    
    


def printAirlinesFlightInfo(airD):
    print(get12HourTime(1300))
    print(get12HourTime(900))
    count=0
    for airline in airD:
        print("AIRLINE=>>",airline)
        for flightNumber in airD[airline]:
            print("FLIGHT NUMBER=>>",flightNumber)
            for cities in airD[airline][flightNumber]:
                print("Departure Locaton"+" "+cities[0],"    "+"Departure Time"+" "+get12HourTime(cities[1]))
            print("\n")
        print("\n")



def main():
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
                   1102:[["BNA",1100],["HOU",1450]]}}
    printAirlinesFlightInfo(flightsD)
    

main()
