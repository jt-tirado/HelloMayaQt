import argparse
import socket

HOST = "127.0.0.1"  # the local host
PORT = 54322  # The same port as used by the server
PLUGIN = "HelloMayaQt.mll"

def main():
    # Initialize parser
    parser = argparse.ArgumentParser()
     
    # Adding optional argument
    parser.add_argument("-p", "--post", action="store_true")
     
    # Read arguments from command line
    args = parser.parse_args()
    
    client: socket.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
    try:
        client.connect((HOST, PORT))
    except ConnectionRefusedError:
        return

    command = ""
     
    if not args.post:
        command = "cmds.unloadPlugin(\"{}\")".format(PLUGIN)
    else:
        command = "cmds.loadPlugin(\"{}\")".format(PLUGIN)
        
    client.send(str.encode(command))
        
    client.close()
    return
    
if __name__ == "__main__":
    main()