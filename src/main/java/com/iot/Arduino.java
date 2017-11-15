package com.iot;

import com.adventurer.springserialport.connector.AbstractSpringSerialPortConnector;

import java.io.IOException;
import org.springframework.stereotype.Component;
@Component
public class Arduino extends AbstractSpringSerialPortConnector {

    public String hol = "0";
    public void processData(String line){
        
        if(line == null){
            System.out.println("Line es NULL");
        }else{
            System.out.println("Line NO es NULL");
            if(line.equals("1")){
                System.out.println("estamos aqui 1");
                try {
                    int a = Integer.parseInt(hol);
                    a=a+1;
                    String b = String.valueOf(a);
                    sendMessage(b);
                    hol = b;
                    System.out.println("estamos aqui 2");
                } catch (IOException e) {
                    e.printStackTrace();
                  }
            }
            else{
                System.out.println("no entro al if");
            }
        }
        
    }


}
