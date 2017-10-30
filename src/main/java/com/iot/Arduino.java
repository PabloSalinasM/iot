package com.iot;

import com.adventurer.springserialport.connector.AbstractSpringSerialPortConnector;

import java.io.IOException;
import org.springframework.stereotype.Component;
@Component
public class Arduino extends AbstractSpringSerialPortConnector {

    public void processData(String line){

        if(line == "1"){
            try {
                sendMessage("HOLA");
                System.out.println("estamos aqui");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }


}
