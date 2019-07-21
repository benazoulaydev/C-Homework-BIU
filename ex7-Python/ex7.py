"""
*Student name: name and family name
*Student ID: XXXX
*Exercise name: exXXXX
"""
import sys
import os
# permissions and variable assignment
userInput = sys.argv[1]
os.chmod(userInput, 0o777)
output = sys.argv[2]
os.chmod(output, 0o777)
def pre_processing():
    """
    this func take the info in the input.txt file and make a dictionary
    out of it every movie as key and actor as value
    Keyword Arguments : ---
    return : a dictionary of info in txt
    """
    dictOfCinema = {}
    print("Processing...")
    with open(userInput, 'r') as fileHandle:
        # for each line in text file
        for line in fileHandle:
            # create a list from line for each separated comma value
            myList = line.split(",")
            # remove te \n and extern space in all elements in list
            myList = [currField.strip() for currField in myList]
            # keep the string of the actor
            actors = myList[0]
            # remove the first element in list here actor
            myList.pop(0)
            # add to dictionary dictOfCinema movies as key and actors as values
            for item in myList:
                dictOfCinema.setdefault(item, []).append(actors)
    # close the open file movie.txt
    fileHandle.close()
    return dictOfCinema
def menu():
    """
    this func display the menu
    Keyword Arguments : keyword input by user choice
    return : -----
    """
    # create a dictionary
    dictOfCinema = {}
    # dic is equal to returned value by prepocess func
    dictOfCinema = pre_processing()
    # user online var to change the while infinite loop if exit
    userOnline = True
    # while infinite loop
    while userOnline:
        menu = "Please select an option:" \
               "\n1) Query by movies" \
               "\n2) Query by actor" \
               "\n3) Insert a new movie" \
               "\n4) Save and Exit" \
               "\n5) Exit"
        print(menu)
        # menu display with user input
        userChoice = input()
        if userChoice == "1":
            # call queryByMovie function
            queryByMovie(dictOfCinema)
        elif userChoice == "2":
            # call queryByActors function
            queryByActors(dictOfCinema)
        elif userChoice == "3":
            # call newmovie function
            newmovie(dictOfCinema)
        elif userChoice == "4":
            # call saveAndExit function
            saveAndExit(dictOfCinema)
            userOnline = False
        elif userChoice == "5":
            # exit
            sys.exit()
        else:
            print('Error')
def newmovie(dictOfCinema):
    """
    this func add a new movie to the dictionary
    Keyword Arguments : new movie name, actors,
    return : the updated dictionary
    """
    # print message to user  and ask for input
    buffer = input("Please insert a new movie:\n")
    # create a list from buffer for each separated comma value
    bufferList = buffer.split(",")
    # remove te \n and extern space in all elements in list
    bufferList = [area.strip() for area in bufferList]
    # keep the string of the movie
    movie = bufferList[0]
    if not movie:
        print('Error')
        return
    # remove the first element in buffer here movie
    bufferList.pop(0)
    # check if there is no actor
    if not bufferList:
        print('Error')
        return
    # add to dictionary dictOfCinema movies as key and actors as values
    for actors in bufferList:
        # check if the actor field is empty with ,
        if not actors:
            print('Error')
            return
        dictOfCinema.setdefault(movie, []).append(actors)
    return dictOfCinema
def saveAndExit(dictOfCinema):
    """
    this func save the dictionary into an output file
    and exit
    Keyword Arguments : -----
    return : out.txt
    """
    # create dictionary with keys movie sorted lexicography
    dicSortedKeyMovie = {}
    dicSortedKeyActor = {}
    # create dictionary inversed keys as value and values as keys
    dicSortedKeyMovie = orderedDicKeyMovie(dictOfCinema)
    # here we create the inversed dictionary with key sorted so now value are sorted
    dicSortedKeyActor = orderedDicKeyActor(dicSortedKeyMovie)
    # permission to write in out.txt
    # open the file out.txt with write permission and for each key write the values
    with open(output, 'w') as fileHandle:
        for key, value in dicSortedKeyActor.items():
            stringInputFormat = ", ".join([str(movieFiled) for movieFiled in value])
            fileHandle.write('%s, %s\n' % (key, stringInputFormat))
    # close the file previously open
    fileHandle.close()
def queryByMovie(dictOfCinema):
    """
    this func ask for two movies and display actors
    in accordance to the user choice &,|,^
    Keyword Arguments : two movies and a &,|,^ operator
    return : ---
    """
    # print message to user  and ask for input
    buffer = input("Please select two movies and an operator(&,|,^) separated with ',':\n")
    counterMovie1 = 0
    counterMovie2 = 0
    if not buffer:
        # check if the input is empty with ,
        print('Error')
        return
    # create a list from buffer for each separated comma value
    bufferList = buffer.split(",")
    if not bufferList:
        # check if the first movie field is empty
        print('Error')
        return
    if not bufferList[0]:
        # check if the second movie field is empty
        print('Error')
        return
    bufferList.pop(0)
    if not bufferList:
        # check if the operator field is empty
        print('Error')
        return
    bufferList.pop(0)
    # create a list from buffer for each separated comma value
    bufferListHelper = buffer.split(",")
    # remove te \n and extern space in all elements in list
    bufferListHelper = [area.strip() for area in bufferListHelper]
    # search if movie input is in  movies dictionary
    for theMovies in dictOfCinema:
        if bufferListHelper[0] == theMovies:
            # counter to know if the actor exist in the dic
            counterMovie1 += 1
        if bufferListHelper[1] == theMovies:
            # counter to know if the actor exist in the dic
            counterMovie2 += 1
    # if the movies are not in the dictionary
    if counterMovie1 is 0 or counterMovie2 is 0:
        # check if the actor field is empty with ,
        print('Error')
        return
    # order the movie dictionary
    orderedMoviesKey = orderedDicKeyMovie(dictOfCinema)
    # inverse the movie key dictionay to actor key sorted
    orderedActorKey = orderedDicKeyActor(orderedMoviesKey)
    # compare the two movies by calling the func
    compareMovies(orderedActorKey, bufferListHelper)


def queryByActors(dictOfCinema):
    """
    this func ask for actor and print
    all of the actor that play in movies with him
    Keyword Arguments : an actor
    return : ---
    """
    # print message to user  and ask for input
    buffer = input("Please select an actor:\n")
    # create a list from buffer for each separated comma value
    if not buffer:
        # check if the actor field is empty with ,
        print('Error')
        return
    # remove te \n and extern space in all elements in list
    buffer = buffer.strip()
    # initialize set
    actorSet = set()
    # initialize counter
    counter = 0
    # search for actor in  movies in dictionary
    for theMovies in dictOfCinema:
        for theActors in dictOfCinema[theMovies]:
            if theActors == buffer:
                # counter to know if the actor exist in the dic
                counter += 1
                for player in dictOfCinema[theMovies]:
                    # add all of the actors to a set
                    actorSet.add(player)
    # if the actor input is not  found print error
    if counter == 0:
        print("Error")
        return
    # if set  is empty print no actor
    if len(actorSet) is 0:
        print("There are no actors in this group")
        return
    # remove the input user actor in the set
    actorSet.remove(buffer)
    # sort the actor set
    sortedActors = sorted(actorSet)
    # print separated by comma
    print(', '.join(sortedActors))


def compareMovies(orderedActorKey, bufferListHelper):
    """
    this func compare two movies with a specific operator
    and return the print of actors
    Keyword Arguments : 2 movies 1 operator
    return : ---
    """
    # register 3 variable from buffer
    movie1 = bufferListHelper[0]
    movie2 = bufferListHelper[1]
    operator = bufferListHelper[2]
    # initialise sets
    firstSet = set()
    secondSet = set()
    # create 1 set of actors for each movie
    for theActors in orderedActorKey:
        for theMovies in orderedActorKey[theActors]:
            if theMovies == movie1:
                firstSet.add(theActors)
            if theMovies == movie2:
                secondSet.add(theActors)

    # for each operator do the good operation
    if operator == '|':
        # sorted Set of all actors
        sortedSetOr = sorted(firstSet | secondSet)
        # if set is empty
        if len(sortedSetOr) is 0:
            print("There are no actors in this group")
            return
        # print final result comma separated
        print(', '.join(sortedSetOr))
    elif operator == '&':
        # sorted Set of common actor of 2 sets
        sortedSetAnd = sorted(firstSet & secondSet)
        # if set is empty
        if len(sortedSetAnd) is 0:
            print("There are no actors in this group")
            return
        # print final result comma separated
        print(', '.join(sortedSetAnd))
    elif operator is '^':
        # sorted Set of not common actor of 2 sets
        sortedSetNot = sorted((firstSet | secondSet) - (firstSet & secondSet))
        # if set is empty
        if len(sortedSetNot) is 0:
            print("There are no actors in this group")
            return
        # print final result comma separated
        print(', '.join(sortedSetNot))
    else:
        print('Error')
        return

    return


def orderedDicKeyMovie(dictOfCinema):
    """
    this func take the dictionary and order it
    Keyword Arguments : the dictionary
    return : the ordered lexicography dictionary
    """
    # create dictionary with keys movie sorted lexicography
    dicSortedKeyMovie = {}
    # here we create a list of sorted movie lexicography
    keysSortedMovie = sorted(dictOfCinema.keys())
    # in that sorted list we create a dictionary for each sorted key add values
    for itemMovie in keysSortedMovie:
        dicSortedKeyMovie.setdefault(itemMovie, dictOfCinema[itemMovie])
    return dicSortedKeyMovie


def orderedDicKeyActor(dictOfCinema):
    """
    this func take the dictionary inverse it
    every movie become value and actors key
    it also order it
    Keyword Arguments : the dictionary
    return : the ordered lexicography dictionary
    """
    # create dictionary inversed keys as value and values as keys
    inversedDict = {}
    # create dictionary with keys actor sorted lexicography
    dicSortedKeyActor = {}
    # here we create the inversed dictionary with key sorted so now value are sorted
    for k in dictOfCinema:
        for v in dictOfCinema[k]:
            inversedDict.setdefault(v, []).append(k)
    # here we create a list of sorted actors lexicography
    keysSortedMovie = sorted(inversedDict.keys())
    # in that sorted list we create a dictionary for each sorted key add values
    for itemActors in keysSortedMovie:
        dicSortedKeyActor.setdefault(itemActors, inversedDict[itemActors])
    return dicSortedKeyActor


# Menu func calling
menu()
