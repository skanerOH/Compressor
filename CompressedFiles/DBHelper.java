package com.example.lab4;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DBHelper extends SQLiteOpenHelper {

    public static final int DATABASE_VERSION = 1;
    public static final String DATABASE_NAME = "lab4_db";
	//table name
    public static final String TABLE_UNIV = "Universities";
	//column names for database
    public static final String KEY_ID = "id";
    public static final String KEY_NAME = "name";
    public static final String KEY_ADDRESS = "address";
    public static final String KEY_STUDENTS_COUNT = "students_count";
    public static final String KEY_RANK = "rank";

    public DBHelper(@Nullable Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table " + TABLE_UNIV + "(" + KEY_ID + " integer primary key autoincrement," + KEY_NAME + " text," +
                KEY_ADDRESS + " text," + KEY_STUDENTS_COUNT + " integer," + KEY_RANK + " integer" + ")");
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("drop table if exists " + TABLE_UNIV);

        onCreate(db);
    }

    public boolean insertData(String name, String address, int students_count, int rank)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(KEY_NAME, name);
        contentValues.put(KEY_ADDRESS, address);
        contentValues.put(KEY_STUDENTS_COUNT, students_count);
        contentValues.put(KEY_RANK, rank);
        long res = db.insert(TABLE_UNIV, null, contentValues);
        if (res == -1)
            return false;
        return true;
    }

    public Cursor getAllData(){
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor res = db.rawQuery("select * from "+TABLE_UNIV, null);
        return res;
    }

    public Cursor findUsingId(int id)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor res = db.rawQuery("select * from "+TABLE_UNIV + " where " + KEY_ID + " = " + Integer.toString(id), null);
        return res;
    }

    public boolean updateData(int id, String name, String address, int students_count, int rank)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues contentValues = new ContentValues();
        contentValues.put(KEY_ID, id);
        contentValues.put(KEY_NAME, name);
        contentValues.put(KEY_ADDRESS, address);
        contentValues.put(KEY_STUDENTS_COUNT, students_count);
        contentValues.put(KEY_RANK, rank);
        db.update(TABLE_UNIV, contentValues, " id = ?", new String[]{Integer.toString(id)});
        return true;
    }

    public int deleteData(int id)
    {
        SQLiteDatabase db = this.getWritableDatabase();
        return db.delete(TABLE_UNIV, " id = ?", new String[]{Integer.toString(id)} );
    }
	//requesting univercities with rank>3000 and not from Kiev
    public Cursor firstRequest()
    {
        SQLiteDatabase db = this.getWritableDatabase();
        Cursor res = db.rawQuery("select * from " + TABLE_UNIV + " where " + "( NOT ( "+KEY_ADDRESS+ " = " + " 'Kiev' ) )" + " AND " + "( " + KEY_RANK +" > 3000 " + " )", null);
        return res;
    }
	//request max rank in table
    public int secondRequestMax() {
        SQLiteDatabase db =this.getWritableDatabase();
        Cursor res = db.rawQuery("select MAX(" + KEY_RANK + ") from " + TABLE_UNIV, null);
        if (res.getCount()==0) return -1;
        res.moveToFirst();
        return Integer.parseInt(res.getString(0));
    }
	//request min rank in table
    public int secondRequestMin() {
        SQLiteDatabase db =this.getWritableDatabase();
        Cursor res = db.rawQuery("select MIN(" + KEY_RANK + ") from " + TABLE_UNIV, null);
        if (res.getCount()==0) return -1;
        res.moveToFirst();
        return Integer.parseInt(res.getString(0));
    }
}
