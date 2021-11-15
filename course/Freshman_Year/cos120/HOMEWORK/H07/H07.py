def remove_dups(astring):
    
    k = set(astring)

    x = len(astring) - len(set(astring))

    return k, x

#print(remove_dups("mississippi"))   #should print misp


def rot13(mess):
    cipher=""
    placeholder=0
    for ch in mess:
        if ord(ch)>109:
            placeholder=(ord(ch)%109)+96
            cipher+=chr(placeholder)
        else:
            cipher+=chr(ord(ch)+13)
    print(cipher)
    
rot13("Realdude")


