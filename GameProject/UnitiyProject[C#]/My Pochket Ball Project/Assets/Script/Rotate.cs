using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotate : MonoBehaviour
{
    public float speed = 10.0f;         //ȸ���ӵ�
    private void Update()
    {
        Orbit_Rotation();
    }

    void Orbit_Rotation()
    {
        transform.Rotate(Vector3.down * speed * Time.deltaTime);
        //transform.Rotate(Vector3 EularAngle)
    }
}
