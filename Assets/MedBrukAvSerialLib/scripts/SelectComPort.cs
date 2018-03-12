using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class SelectComPort : MonoBehaviour {

    private string[] ports = SerialPort.GetPortNames();
    // Use this for initialization
    void Start () {
        // Get a list of serial port names.
       

        Debug.Log("The following serial ports were found:");

        // Display each port name to the console.
        foreach (string port in ports)
        {
            Debug.Log(port);
        }


    }

    public string Port(int num)
    {
        Debug.Log("Setting port: " + ports[num]);
        return ports[num];
    }
    

}
