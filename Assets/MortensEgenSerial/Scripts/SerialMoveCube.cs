using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

// Mortens hardcoded serial 

public class SerialMoveCube : MonoBehaviour {

  static string portName = "COM4";
  static int baudRate = 9600;


    SerialPort sp = new SerialPort(portName, baudRate);


	// Use this for initialization
	void Start () {
        Debug.Log("Starting");


        // open serial con.
        sp.Open();
        sp.ReadTimeout = 1;


    }

    // Update is called once per frame
    void Update () {
	
        if (sp.IsOpen)
        {
          

            try
            {
               
                string serialInput = sp.ReadLine();
                print(serialInput);

                switch (serialInput)
                {
                    case "0":
                        SetCubeColor(Color.white);
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
                        SetCubeColor(Color.grey);
                        break;
                    case "7":
                        SetCubeColor(Color.magenta);
                        break;
                    default:
                       
                        break;
                }

            }
            catch
            {
               

            }
        }
        else
        {
            Debug.Log("Serial Disconnected");


        }


        if (Input.GetKeyDown(KeyCode.A))
        {
           Debug.Log("Sending; A");
           sp.Write("A");
           
        }

        if (Input.GetKeyDown(KeyCode.Z))
        {
            Debug.Log("Sending Z");
            sp.Write("Z");
            //serialController.SendSerialMessage("Z");
        }
    }

    void SetCubeColor(Color newCol)
    {

        Renderer rend = GetComponent<Renderer>();
        rend.material.color = newCol;
    }

    void OnApplicationQuit()
    {
        Debug.Log("Exiting...");
        sp.Close();
    }
}
