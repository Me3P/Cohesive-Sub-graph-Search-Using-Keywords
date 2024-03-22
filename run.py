import os
from multiprocessing import Pool


def command(file):
    os.system("./run.sh " + file)

if __name__ == '__main__':
    with Pool(8) as p:
        print(p.map(command, ["144.txt",
                              "DD_g138.txt",
                              "MANN-a45.txt", 
                              "bn-human-BNU_1_0025867_session_2-bg.edges",
                              "flickr.edges",
                              "twitter-2010.txt",
                              "as-skitter.txt com-lj.ungraph.txt", 
                              "com-orkut.ungraph.txt"]))