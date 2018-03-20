import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Player {
    
    static int W, H, N, X0, Y0, arriba, abajo, izquierda, derecha;

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        W = in.nextInt(); // width of the building.
        H = in.nextInt(); // height of the building.
        N = in.nextInt(); // maximum number of turns before game over.
        X0 = in.nextInt();
        Y0 = in.nextInt();
        arriba = 0;
        abajo = H;
        izquierda = 0;
        derecha = W;

        // game loop
        while (true) {
            String bombDir = in.next(); // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
            // Write an action using System.out.println()
            // To debug: System.err.println("Debug messages...");
            if(bombDir.equals("U")){
                goUp();
            
            }else if(bombDir.equals("UR")){
                goUp();
                goRight();
            
            }else if(bombDir.equals("R")){
                goRight();
            
            }else if(bombDir.equals("DR")){
                goDown();
                goRight();
            
            }else if(bombDir.equals("D")){
                goDown();
            
            }else if(bombDir.equals("DL")){
                goDown();
                goLeft();
            
            }else if(bombDir.equals("L")){
                goLeft();
            
            }else if(bombDir.equals("UL")){
                goUp();
                goLeft();
            
            }

            // the location of the next window Batman should jump to.
            System.out.println(X0 + " " + Y0);
        }
    }
    public static void goUp(){
        abajo = Y0;
        int ma = Y0 - ((arriba + Y0)/2);
        if (ma < arriba){
            Y0 = Y0 - 1;
        }else{
            Y0 = ma;
        }
    }
    public static void goDown(){
        arriba = Y0;
        Y0 = Y0 + ((abajo - Y0)/2);
    }
    public static void goLeft(){
        derecha = X0;
        int mi = X0 - ((derecha + X0)/2);
        if (mi < derecha){
            X0 = X0 - 1;
        }else{
            X0 = mi;
        }
    }
    public static void goRight(){
        izquierda = X0;
        X0 = X0 + ((derecha - X0)/2);
    }
}