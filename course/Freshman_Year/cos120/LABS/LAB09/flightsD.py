#L09-6
def printAirlines(airD):
    for key,value in airD.items():
        print(key)
#L09-7
def printAirlinesWithFlight(airD,withFlight): 
    pass




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
    printAirlines(flightsD)
    #printAirlinesWithFlight(flightsD,1102)

main()
