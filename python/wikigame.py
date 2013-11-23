import mechanize #mechanize
import re

verbose = True

prename = "http://en.wikipedia.org/wiki/"
start = "Radiohead"
target = "Pornography"

been_here = ["Main_Page"]#List of links already visited.

#list of regexp patterns matched by undesired links
nonos = []
nonos.append(re.compile("(.*)#(.*)"))
nonos.append(re.compile("(.*):(.*)"))

#Pattern to match link to wikipedia articles
linkRE = re.compile('"/wiki/(.*?)"')

#Assign a virtual browser
br = mechanize.Browser()
br.addheaders = [('User-agent', 'Mozilla/5.0')] # A white lie

def is_bad_link(link):
    '''Determines if a link is 'bad' i.e. matches a pattern in the nonos list
    bad links include links from the TOC, for instance.'''
    for bad in nonos:
        if bad.match(link): return True
    return False

def yoink(url):
    '''returns a list of all hyperlinks on input url'''
    global been_here
    result = []
    #Open target URL
    site = br.open(url)
    # Read URL. Only keep the part before the 'context boxes' at the bottom
    data = site.read().split('navbox-title')[0]
    #Loop over everything that looks like a link
    for link in linkRE.findall(data):
        if link in been_here:
            continue
        if is_bad_link(link):
            continue
        else:
            been_here.append(link)
            result.append(link)

    return result

best_path = []

routes = [[start]] #List of all routes branching out from the starting point
current_links = [] #List of the most recently harvested batch of links
nsteps = 20 #Number of updates per branch

#Loop over paths while adding all new possible paths to list.
while not best_path:
    counter = next_step = 0
    npaths = len(routes)
    step_size = npaths/nsteps
    temp = []
    print "\n","-"*42,"\nGrabbing links from %s URLs...\n" % npaths,
    print "Current branch depth: %s\n" % len(routes[0]), "-"*42
    for path in routes:
        #First, check wether to update user on progress
        if counter % 20 == 0 and not verbose:
            percent = 100*(float(counter)/npaths)
            print '{0:.2g}%...'.format(percent),

        current_links = yoink(prename+path[-1]) #Grab links from current page
        if verbose: print "URL %s of %s - Grabbed %s links from article %s" % (counter, npaths, len(current_links), path[-1])
        #Add copies of path plus all links to temp list
        for link in current_links:
            if link == target:
                best_path = path
                best_path.append(link)
                break
            else:
                temp.append(path+[link])
                pass
        if best_path:
            break
        else:
            counter += 1
    routes = temp

print "\n", "-"*42
print "Shortest path from the article on {0} to {1} has {2} links.".format(start, target, len(best_path))
print "The shortest path is:"
for i in range(0,len(best_path)):
    print best_path[i],
    if not i == len(best_path)-1: print "-->",