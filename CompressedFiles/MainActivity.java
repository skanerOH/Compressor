package com.example.lab4;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    DBHelper dbHelper;

    EditText et_name, et_address, et_students_count, et_rank, et_id;
    Button btn_add, btn_view, btn_freq, btn_sreq;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        dbHelper = new DBHelper(this);

        et_name=findViewById(R.id.editTextName);
        et_address=findViewById((R.id.editTextAddress));
        et_rank=findViewById(R.id.editTextRank);
        et_students_count=findViewById(R.id.editTextStudentsCount);
        et_id=findViewById(R.id.editTextID);

        btn_add = findViewById(R.id.buttonAdd);
        btn_view = findViewById(R.id.buttonViewData);
        btn_freq = findViewById(R.id.buttonFRequest);
        btn_sreq = findViewById(R.id.buttonSRequest);

        AddBtn();
        ViewBtn();
        ConfigureEditButton();
        ConfigureNextButtonInfo();
        FReqButton();
        SReqButton();
    }
//Button to add new univ
    public void AddBtn()
    {
        btn_add.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        int sc=0;
                        int rank=0;
                        String name="";
                        String address="";
                        if (showStringWarning(et_name.getText().toString(), "name"))
                            return;
                        name = et_name.getText().toString();
                        if (showStringWarning(et_name.getText().toString(), "address"))
                            return;
                        address = et_address.getText().toString();
                        if (showStringWarning(et_students_count.getText().toString(), "student count"))
                            return;
                        sc= Integer.parseInt(et_students_count.getText().toString());
                        if (showStringWarning(et_name.getText().toString(), "rank"))
                            return;
                        rank= Integer.parseInt(et_rank.getText().toString());

                        boolean isInserted = dbHelper.insertData(name, address, sc, rank);

                        if (isInserted)
                        {
                            Toast.makeText(MainActivity.this, "Added successfully",Toast.LENGTH_LONG).show();
                        }
                        else
                        {
                            Toast.makeText(MainActivity.this, "Insertion error",Toast.LENGTH_LONG).show();
                        }
                    }
                }
        );
    }
//View all button
    public void ViewBtn()
    {
        btn_view.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Cursor res = dbHelper.getAllData();
                        if (res.getColumnCount()==0){
                            showMessage("Error", "No data");
                            return;
                        }

                        StringBuffer buffer = new StringBuffer();
                        while (res.moveToNext()){
                            buffer.append("Id: "+ res.getString(0) + "\n");
                            buffer.append("Name: "+ res.getString(1) + "\n");
                            buffer.append("Address: "+ res.getString(2) + "\n");
                            buffer.append("Students: "+ res.getString(3) + "\n");
                            buffer.append("Rank: "+ res.getString(4) + "\n");
                            buffer.append("\n");
                        }

                        showMessage("Universities", buffer.toString());
                    }
                }
        );
    }
	//Button to edit univ
    private void ConfigureEditButton()
    {
        Button nextButton = (Button) findViewById(R.id.buttonEdit);
        nextButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent=new Intent(MainActivity.this,EditActivity.class);
                if (et_id.getText().toString().equals(""))
                {
                    Toast.makeText(MainActivity.this, "Invalid ID",Toast.LENGTH_LONG).show();
                    return;
                }
                int id = Integer.parseInt(et_id.getText().toString());
                if (dbHelper.findUsingId(id).getCount()!=0) {
                    intent.putExtra("ID", id);
                    startActivity(intent);
                }
                else
                {
                    Toast.makeText(MainActivity.this, "Invalid ID",Toast.LENGTH_LONG).show();
                }
            }
        });
    }

    public void showMessage(String title, String message){
        AlertDialog.Builder builder=new AlertDialog.Builder(this);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setMessage(message);
        builder.show();
    }

    public boolean showStringWarning(String inp, String name)
    {
        if (inp.equals(""))
        {
            Toast.makeText(MainActivity.this, "Invalid "+ name, Toast.LENGTH_LONG).show();
            return true;
        }
        return false;
    }
//Button to request all
    public void FReqButton()
    {
        btn_freq.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Cursor res = dbHelper.firstRequest();
                        if (res.getColumnCount()==0){
                            showMessage("First request", "Nothing found");
                            return;
                        }

                        StringBuffer buffer = new StringBuffer();
                        while (res.moveToNext()){
                            buffer.append("Id: "+ res.getString(0) + "\n");
                            buffer.append("Name: "+ res.getString(1) + "\n");
                            buffer.append("Address: "+ res.getString(2) + "\n");
                            buffer.append("Students: "+ res.getString(3) + "\n");
                            buffer.append("Rank: "+ res.getString(4) + "\n");
                            buffer.append("\n");
                        }

                        showMessage("First request", buffer.toString());
                    }
                }
        );
    }
//Button for specioal request
    public void SReqButton()
    {
        btn_sreq.setOnClickListener(
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        int max = dbHelper.secondRequestMax();
                        int min = dbHelper.secondRequestMin();

                        StringBuffer buffer = new StringBuffer();
                        buffer.append("Max ranking value = " + Integer.toString(max) + "\n");
                        buffer.append("Min ranking value = " + Integer.toString(min) + "\n");

                        showMessage("Second request", buffer.toString());
                    }
                }
        );
    }
//Button to move to Info Activity
    private void ConfigureNextButtonInfo()
    {
        Button nextButton = (Button) findViewById(R.id.buttonIfo);
        nextButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this,AInfoActivity.class));
            }
        });
    }
}
