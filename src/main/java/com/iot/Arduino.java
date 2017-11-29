package com.iot;

import com.adventurer.springserialport.connector.AbstractSpringSerialPortConnector;

import java.io.IOException;
import org.springframework.stereotype.Component;
@Component
public class Arduino extends AbstractSpringSerialPortConnector {

    private String temperatura = "0";
    private String tiempo = "00 00 00";
    private String salida = "";
    private String estadoAnterior = "";
    private String [] entradaProcesada;
    public void processData(String arduinoOut){

        if(arduinoOut.equals(this.estadoAnterior)){

        }else{

            if(true){

                System.out.println(arduinoOut);

                try {

                    sendMessage("T 028 00 00 05");


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
