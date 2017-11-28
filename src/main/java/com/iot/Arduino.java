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
        //arduinoOut = "100 00 20 00";

        /*entradaProcesada = arduinoOut.split("\\s");
        System.out.println(entradaProcesada[0]);
        System.out.println(entradaProcesada[1]);
        System.out.println(entradaProcesada[2]);
        System.out.println(entradaProcesada[3]);*/
        if(arduinoOut.equals(this.estadoAnterior)){
           //System.out.println("Line es NULL");
        }else{
            //System.out.println("Line NO es NULL");

            if(true){

                System.out.println(arduinoOut);

                    int a = Integer.parseInt("1");
                try {
    
                    sendMessage("T 123 45 67 89");

                    System.out.println("conchetumaree");
                } catch (IOException e) {
                    e.printStackTrace();
                }

                System.out.println("estamos aqui 2");

            }
            else{
                System.out.println("no entro al if");
            }
        }
        
    }


}
