import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class DateServer {
    public static void main(String[] args){
        try {
            ServerSocket sock = new ServerSocket(5613);

            while(true){
                Socket client  = sock.accept();
                PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
                // write the date to the socket
                pout.println(new java.util.Date().toString());

                client.close();
            }
        }
            catch (IOException ioe){
                System.out.println(ioe);
            }
        }
    }
}
