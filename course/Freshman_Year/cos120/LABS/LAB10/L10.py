#L10-01
class Time:
    def   __init__(self, hours, minutes, seconds):
        if hours < 0 or hours >23:
            hours=0
            minutes=0
            seconds=0
        if minutes < 0 or minutes >60:
            hours=0
            minutes=0
            seconds=0
        if seconds < 0 or seconds >60:
            hours=0
            minutes=0
            seconds=0
        
        self.hours = hours 
        self.minutes = minutes 
        self.seconds = seconds 
#L10-02
    def getTime(self):
        if self.hours < 10:
            self.hours = "0" + str(self.hours)
        if self.minutes < 10:
            self.minutes = "0" + str(self.minutes)
        if self.seconds < 10:
            self.seconds = "0" + str(self.seconds)
        x = str(self.hours)+":"+ str(self.minutes)+":"+ str(self.seconds)
        return x
#L10-03
    def addSecond(self): 
        if self.seconds+1>59:
            self.seconds=0
            self.minutes+=1
            if self.minutes+1>59:
                self.minutes=0
                self.hours+=1
                if self.hours+1>23:
                    self.hours=0
        else:
            self.seconds+=1
        return self.hours,self.minutes,self.seconds
            

    def subtractSecond(self):
        if self.seconds-1<0:
            self.seconds=59
            self.minutes-=1
            if self.minutes-1<0:
                self.minutes=59
                self.hours-=1
                if self.hours-1<0:
                    self.hours=23
        else:
            self.seconds-=1
        return self.hours,self.minutes,self.seconds

#L10-04
    def getSecond(self):
        return self.seconds

    def getMinute(self):
        return self.minutes

    def getHour(self):
        return self.hours
#L10-05
    def changeMinutes(self, change):
        if self.minutes+change>59:
            return -1
        else:
            return self.minutes+change

    def changeHours(self, change):
        if self.hours+change>59:
            return -1
        else:
            return self.hours+change

    def changeSeconds(self, change):
        if self.seconds+change>59:
            return -1
        else:
            return self.seconds+change
#L10-06
    def timeDiff(self,time1,time2):
        hours1=myTime1.getHour()
        hours2=myTime2.getHour()
        hours1=hours1*3600
        hours2=hours2*3600
        minutes1=myTime1.getMinute()
        minutes2=myTime2.getMinute()
        minutes1=minutes1*60
        minutes2=minutes2*60
        seconds1=myTime1.getSecond()
        seconds2=myTime2.getSecond()
        firstTime=hours1+minutes1+seconds1
        secondTime=hours2+minutes2+seconds2
        difference=abs(firstTime-secondTime)
        integerHours=difference//3600
        secondsHours=3600*integerHours
        difference=difference-secondsHours
        integerMinutes=difference//60
        secondsMinutes=60*integerMinutes
        difference=difference-secondsMinutes
        return Time(integerHours,integerMinutes,difference)
    def addTimes(self):
        if self.hours < 10:
            self.hours = "0" + str(self.hours)
        if self.minutes < 10:
            self.minutes = "0" + str(self.minutes)
        if self.seconds < 10:
            self.seconds = "0" + str(self.seconds)
        x = str(self.hours)+":"+ str(self.minutes)+":"+ str(self.seconds)
        return x
        

t=Time(22,45,28)
myTime1=Time(20,10,2)
myTime2=Time(1,1,1)
##print(Time.getTime(t))
##print(Time.addSecond(t))
##print(Time.subtractSecond(t))
##print(Time.getSecond(t))
##print(Time.getMinute(t))
##print(Time.getHour(t))
##print(Time.changeMinutes(t,20))
##print(Time.changeHours(t,20))
##print(Time.changeSeconds(t,20))
##print(Time.timeDiff(t,myTime1,myTime2))
##print(Time.addTimes(t))


