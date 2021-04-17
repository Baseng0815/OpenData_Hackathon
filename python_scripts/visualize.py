import sys
import os
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

# no toolbar
mpl.rcParams['toolbar'] = 'None' 

if __name__ == "__main__":
    # get heights in stdin seperated by whitespace
    heights = []
    for line in sys.stdin: # change to sys.stdin if reading lines
        for height in line.split(" "):
            try:
                heights.append(int(height))
            except ValueError:
                pass

    # calculate how much heightmeters were uphill or downhill
    uphill = 0
    downhill = 0
    for idx, height in enumerate(heights):
        if idx < len(heights) - 1:
            diff = height - heights[idx + 1]
            if diff < 0:
                uphill += abs(diff)
            else:
                downhill += diff
        
    # plot the list of heights
    xs = np.arange(len(heights))
    heights_series = np.array(heights).astype(np.double)
    heights_mask = np.isfinite(heights_series)

    fig = plt.figure()
    plt.style.use('classic')
    plt.plot(xs[heights_mask], heights_series[heights_mask], linestyle=" ", marker=" ")
    plt.ylim(ymin=min(heights)) # y axis starts at lowest entry in heights instead of 0
    plt.xticks([]) # don't match with actual data
    plt.title("Höhenprofil")
    plt.ylabel("Höhe in Metern")
    plt.fill_between(xs, heights_series, color="#BAC8EF")

    # additional information
    info_text = f"""
Berg auf / m: {str(uphill)}
Berg ab / m: {str(downhill)}
"""
    plt.figtext(.15, .15, info_text)
    
    # show or safe
    save_flag_idx = False
    try:
        save_flag_idx = sys.argv.index("-s")
    except ValueError:
        pass
    if save_flag_idx:
        if len(sys.argv) > save_flag_idx + 1:
            plt.savefig(sys.argv[save_flag_idx + 1])
        else:
            plt.savefig("Höhenprofil.png")
    else:
        plt.show()


