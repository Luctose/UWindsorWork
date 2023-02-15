using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        // Setting the camera's transform
        gameObject.transform.position = new Vector3(5.5F, 8.5F, -12);
        gameObject.transform.localEulerAngles = new Vector3(30, -25, 0);
    }

    void FixedUpdate() {
        cameraMove();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    /**
        This function moves the camera forwards or backwards, if pressing the 'w' or 's' keys, respectively
    */
    void cameraMove(){
        if(Input.GetKey("w")){
            gameObject.transform.Translate(0, 0, 0.5F * Time.fixedDeltaTime);
        }else if(Input.GetKey("s")){
            gameObject.transform.Translate(0, 0, -0.5F * Time.fixedDeltaTime);
        }
    }
}
