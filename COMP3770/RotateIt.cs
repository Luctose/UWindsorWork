using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RotateIt : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void FixedUpdate() {
        gameObject.transform.Rotate(30 * Time.fixedDeltaTime, 60 * Time.fixedDeltaTime, 90 * Time.fixedDeltaTime);
    }
}
