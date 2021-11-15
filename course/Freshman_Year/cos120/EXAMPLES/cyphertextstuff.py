def twoRailTranscriptEncryption(plainTest):
    odds=""
    evens=""
    for i in range(0,len(plainText),2):
        evens="evens"+plainText[i]
    for i in range(1,len(plainText),2):
        odds="odds"+plainText[i]
    return odds+evens   
        

        
