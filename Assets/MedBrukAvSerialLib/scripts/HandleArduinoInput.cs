using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class HandleArduinoInput : MonoBehaviour {

    public SerialController serialController;

    // Initialization
    void Start()
    {
        serialController.enabled = false;
        serialController.portName = GetComponent<SelectComPort>().Port(0);


        // serialController = GameObject.Find("SerialController").GetComponent<SerialController>();
        serialController.enabled = true;


        Debug.Log("Press A or Z to execute some actions");





    }

    // Executed each frame
    void Update()
    {
        //---------------------------------------------------------------------
        // Send data
        //---------------------------------------------------------------------

        // If you press one of these keys send it to the serial device. A
        // sample serial device that accepts this input is given in the README.
        if (Input.GetKeyDown(KeyCode.A))
        {
            Debug.Log("Sending A");
            serialController.SendSerialMessage("A");
        }

        if (Input.GetKeyDown(KeyCode.Z))
        {
            Debug.Log("Sending Z");
            serialController.SendSerialMessage("Z");
        }


        //---------------------------------------------------------------------
        // Receive data
        //---------------------------------------------------------------------

        string message = serialController.ReadSerialMessage();

        if (message == null)
            return;

        // Check if the message is plain data or a connect/disconnect event.
        if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_CONNECTED))
            Debug.Log("Connection established");
        else if (ReferenceEquals(message, SerialController.SERIAL_DEVICE_DISCONNECTED))
            Debug.Log("Connection attempt failed or disconnection detected");
        else
            Debug.Log("Message arrived: " + message);


       
      
        

            switch (message)
            {
                case "0":
                    SetCubeColor(Color.white);
                     startRotation(new Vector3(-1, -3, -4));
                break;
                case "1":
                    SetCubeColor(Color.blue);
                    break;
                case "2":
                    SetCubeColor(Color.yellow);
                    break;
                case "3":
                    SetCubeColor(Color.red);
                    break;
                case "4":
                    SetCubeColor(Color.green);
                    break;
                case "5":
                    SetCubeColor(Color.black);
                    break;
                case "6":
                startRotation(new Vector3(-1, -3, -4));
                break;
                case "7":
     
                    startRotation(new Vector3(2,2,2));
                break;
                default:

                    break;
            }





    }

    void SetCubeColor(Color newCol)
    {

        Renderer rend = GetComponent<Renderer>();
        rend.material.color = newCol;
    }


   void startRotation(Vector3 turn)
    {
        gameObject.GetComponent<Rigidbody>().AddTorque(turn);
       

    }




}
